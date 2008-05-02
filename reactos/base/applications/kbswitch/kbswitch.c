/*
 * PROJECT:         Keyboard Layout Switcher
 * FILE:            base\applications\kbswitch\kbswitch.c
 * PURPOSE:         Switching Keyboard Layouts
 * PROGRAMMERS:     Dmitry Chapyshev (dmitry@reactos.org)
 *                  Colin Finck (mail@colinfinck.de)
 */

#include "kbswitch.h"

#define WM_NOTIFYICONMSG (WM_USER + 248)

TCHAR szKbSwitcherName[] = _T("kbswitcher");


static BOOL
GetLayoutID(LPTSTR szLayoutNum, LPTSTR szLCID);

HINSTANCE hInst;
HANDLE    hProcessHeap;

static HICON
CreateTrayIcon(LPTSTR szLCID)
{
    LANGID lId;
    TCHAR szBuf[3];
    HDC hdc, hdcsrc;
    HBITMAP hBitmap, hBmpNew, hBmpOld;
    RECT rect;
    DWORD bkColor, bkText;
    HFONT hFont = NULL;
    ICONINFO IconInfo;
    HICON hIcon = NULL;

    lId = (LANGID)_tcstoul(szLCID, NULL, 16);
    if (GetLocaleInfo(lId,
                      LOCALE_SISO639LANGNAME,
                      szBuf,
                      sizeof(szBuf) / sizeof(TCHAR)) == 0)
    {
        lstrcpy(szBuf, _T("??\0"));
    }

    hdcsrc = GetDC(NULL);
    hdc = CreateCompatibleDC(hdcsrc);
    hBitmap = CreateCompatibleBitmap(hdcsrc, 16, 16);
    ReleaseDC(NULL, hdcsrc);

    if (hdc && hBitmap)
    {
        hBmpNew = CreateBitmap(16, 16, 1, 1, NULL);
        if (hBmpNew)
        {
            hBmpOld = SelectObject(hdc, hBitmap);
            rect.right = 16;
            rect.left = 0;
            rect.bottom = 16;
            rect.top = 0;

            bkColor = SetBkColor(hdc, GetSysColor(COLOR_HIGHLIGHT));
            bkText  = SetTextColor(hdc, GetSysColor(COLOR_HIGHLIGHTTEXT));

            ExtTextOut(hdc, rect.left, rect.top, ETO_OPAQUE, &rect, _T(""), 0, NULL);

            hFont = CreateFont(-11, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ANSI_CHARSET,
                               OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                               DEFAULT_QUALITY, FF_DONTCARE, _T("Tahoma"));

            SelectObject(hdc, hFont);
            DrawText(hdc, _tcsupr(szBuf), 2, &rect, DT_SINGLELINE|DT_CENTER|DT_VCENTER);
            SelectObject(hdc, hBmpNew);
            PatBlt(hdc, 0, 0, 16, 16, BLACKNESS);
            SelectObject(hdc, hBmpOld);

            IconInfo.hbmColor = hBitmap;
            IconInfo.hbmMask = hBmpNew;
            IconInfo.fIcon = TRUE;

            hIcon = CreateIconIndirect(&IconInfo);

            DeleteObject(hBmpNew);
            DeleteObject(hBmpOld);
            DeleteObject(hFont);
        }
    }

    DeleteDC(hdc);
    DeleteObject(hBitmap);

    return hIcon;
}

static VOID
AddTrayIcon(HWND hwnd)
{
    NOTIFYICONDATA tnid;
    TCHAR szLCID[CCH_LAYOUT_ID + 1];

    GetLayoutID(_T("1"), szLCID);

    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = hwnd;
    tnid.uID = 1;
    tnid.uFlags = NIF_ICON | NIF_MESSAGE;
    tnid.uCallbackMessage = WM_NOTIFYICONMSG;
    tnid.hIcon = CreateTrayIcon(szLCID);

    Shell_NotifyIcon(NIM_ADD, &tnid);
}

static VOID
DelTrayIcon(HWND hwnd)
{
    NOTIFYICONDATA tnid;

    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = hwnd;
    tnid.uID = 1;

    Shell_NotifyIcon(NIM_DELETE, &tnid);
}

static VOID
UpdateTrayIcon(HWND hwnd, LPTSTR szLCID)
{
    NOTIFYICONDATA tnid;

    tnid.cbSize = sizeof(NOTIFYICONDATA);
    tnid.hWnd = hwnd;
    tnid.uID = 1;
    tnid.uFlags = NIF_ICON | NIF_MESSAGE;
    tnid.uCallbackMessage = WM_NOTIFYICONMSG;
    tnid.hIcon = CreateTrayIcon(szLCID);

    Shell_NotifyIcon(NIM_MODIFY, &tnid);
}

static BOOL
GetLayoutID(LPTSTR szLayoutNum, LPTSTR szLCID)
{
    DWORD dwBufLen;
    DWORD dwRes;
    HKEY hKey;
    TCHAR szTempLCID[CCH_LAYOUT_ID + 1];

    // Get the Layout ID
    if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Keyboard Layout\\Preload"), 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
    {
        dwBufLen = sizeof(szTempLCID);
        dwRes = RegQueryValueEx(hKey, szLayoutNum, NULL, NULL, (LPBYTE)szTempLCID, &dwBufLen);

        if (dwRes != ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return FALSE;
        }

        RegCloseKey(hKey);
    }

    // Look for a substitude of this layout
    if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Keyboard Layout\\Substitutes"), 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
    {
        dwBufLen = sizeof(szTempLCID);

        if (RegQueryValueEx(hKey, szTempLCID, NULL, NULL, (LPBYTE)szLCID, &dwBufLen) != ERROR_SUCCESS)
        {
            // No substitute found, then use the old LCID
            lstrcpy(szLCID, szTempLCID);
        }

        RegCloseKey(hKey);
    }
    else
    {
        // Substitutes key couldn't be opened, so use the old LCID
        lstrcpy(szLCID, szTempLCID);
    }

    return TRUE;
}

static BOOL
GetLayoutName(LPTSTR szLayoutNum, LPTSTR szName)
{
    HKEY hKey;
    DWORD dwBufLen;
    TCHAR szBuf[MAX_PATH], szDispName[MAX_PATH], szIndex[MAX_PATH], szPath[MAX_PATH];
    TCHAR szLCID[CCH_LAYOUT_ID + 1];
    HANDLE hLib;
    int i, j, k;

    if(!GetLayoutID(szLayoutNum, szLCID))
        return FALSE;

    wsprintf(szBuf, _T("SYSTEM\\CurrentControlSet\\Control\\Keyboard Layouts\\%s"), szLCID);

    if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, (LPCTSTR)szBuf, 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
    {
        dwBufLen = sizeof(szBuf);

        if (RegQueryValueEx(hKey, _T("Layout Display Name"), NULL, NULL, (LPBYTE)szDispName, &dwBufLen) == ERROR_SUCCESS)
        {
            if (szDispName[0] == '@')
            {
                for (i = 0; i < _tcslen(szDispName); i++)
                {
                    if ((szDispName[i] == ',') && (szDispName[i + 1] == '-'))
                    {
                        for (j = i + 2, k = 0; j < _tcslen(szDispName)+1; j++, k++)
                        {
                            szIndex[k] = szDispName[j];
                        }
                        szDispName[i - 1] = '\0';
                        break;
                    }
                    else szDispName[i] = szDispName[i + 1];
                }

                if (ExpandEnvironmentStrings(szDispName, szPath, MAX_PATH))
                {
                    hLib = LoadLibrary(szPath);
                    if (hLib)
                    {
                        if (LoadString(hLib, _ttoi(szIndex), szPath, sizeof(szPath) / sizeof(TCHAR)) != 0)
                        {
                            _tcscpy(szName, szPath);
                            RegCloseKey(hKey);
                            return TRUE;
                        }
                        FreeLibrary(hLib);
                    }
                }
            }
        }

        dwBufLen = sizeof(szBuf);

        if (RegQueryValueEx(hKey, _T("Layout Text"), NULL, NULL, (LPBYTE)szName, &dwBufLen) == ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            return TRUE;
        }
    }

    return FALSE;
}

BOOL CALLBACK
EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
    SendMessage(hwnd, WM_INPUTLANGCHANGEREQUEST, 0, lParam);
    return TRUE;
}

static VOID
ActivateLayout(HWND hwnd, ULONG uLayoutNum)
{
    HKL hKl;
    TCHAR szLayoutNum[CCH_ULONG_DEC + 1];
    TCHAR szLCID[CCH_LAYOUT_ID + 1];

    _ultot(uLayoutNum, szLayoutNum, 10);
    GetLayoutID(szLayoutNum, szLCID);
    CreateTrayIcon(szLCID);

    // Switch to the new keyboard layout
    UpdateTrayIcon(hwnd, szLCID);
    hKl = LoadKeyboardLayout(szLCID, KLF_ACTIVATE);
    SystemParametersInfo(SPI_SETDEFAULTINPUTLANG, 0, &hKl, SPIF_SENDWININICHANGE);
    EnumWindows(EnumWindowsProc, (LPARAM) hKl);
}

static HMENU
BuildPopupMenu()
{
    HMENU hMenu;
    HMENU hMenuTemplate;
    HKEY hKey;
    DWORD dwIndex, dwSize;
    LPTSTR pszMenuItem;
    MENUITEMINFO mii;
    TCHAR szLayoutNum[CCH_ULONG_DEC + 1];
    TCHAR szName[MAX_PATH];

    hMenu = CreatePopupMenu();

    // Add the keyboard layouts to the popup menu
    if (RegOpenKeyEx(HKEY_CURRENT_USER, _T("Keyboard Layout\\Preload"), 0, KEY_QUERY_VALUE, &hKey) == ERROR_SUCCESS)
    {
        for(dwIndex = 0; ; dwIndex++)
        {
            dwSize = sizeof(szLayoutNum);
            if(RegEnumValue(hKey, dwIndex, szLayoutNum, &dwSize, NULL, NULL, NULL, NULL) != ERROR_SUCCESS)
                break;

            if(!GetLayoutName(szLayoutNum, szName))
                break;

            AppendMenu(hMenu, MF_STRING, _ttoi(szLayoutNum), szName);
        }

        RegCloseKey(hKey);
    }

    // Add the menu items from the popup menu template
    hMenuTemplate = GetSubMenu(LoadMenu(hInst, MAKEINTRESOURCE(IDR_POPUP)), 0);
    dwIndex = 0;

    mii.cbSize = sizeof(mii);
    mii.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_ID;
    mii.dwTypeData = NULL;

    while(GetMenuItemInfo(hMenuTemplate, dwIndex, TRUE, &mii))
    {
        if(mii.cch > 0)
        {
            mii.cch++;
            pszMenuItem = (LPTSTR)HeapAlloc(hProcessHeap, 0, mii.cch * sizeof(TCHAR));

            mii.dwTypeData = pszMenuItem;
            GetMenuItemInfo(hMenuTemplate, dwIndex, TRUE, &mii);

            AppendMenu(hMenu, mii.fType, mii.wID, mii.dwTypeData);

            HeapFree(hProcessHeap, 0, pszMenuItem);
            mii.dwTypeData = NULL;
        }
        else
        {
            AppendMenu(hMenu, mii.fType, 0, NULL);
        }

        dwIndex++;
    }

    return hMenu;
}

LRESULT CALLBACK
WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
    static HMENU hPopupMenu;

    switch (Message)
    {
        case WM_CREATE:
            AddTrayIcon(hwnd);
            hPopupMenu = BuildPopupMenu(hwnd);
            break;

        case WM_NOTIFYICONMSG:
            switch (lParam)
            {
                case WM_LBUTTONDOWN:
                case WM_RBUTTONDOWN:
                {
                    POINT pt;

                    GetCursorPos(&pt);
                    SetForegroundWindow(hwnd);
                    TrackPopupMenu(hPopupMenu, 0, pt.x, pt.y, 0, hwnd, NULL);
                    PostMessage(hwnd, WM_NULL, 0, 0);
                    break;
                }
            }
            break;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case ID_EXIT:
                    SendMessage(hwnd, WM_CLOSE, 0, 0);
                    break;

                case ID_PREFERENCES:
                {
                    SHELLEXECUTEINFO shInputDll = {0};

                    shInputDll.cbSize = sizeof(shInputDll);
                    shInputDll.hwnd = hwnd;
                    shInputDll.lpVerb = _T("open");
                    shInputDll.lpFile = _T("rundll32.exe");
                    shInputDll.lpParameters = _T("shell32.dll,Control_RunDLL input.dll");

                    if (!ShellExecuteEx(&shInputDll))
                        MessageBox(hwnd, _T("Can't start input.dll"), NULL, MB_OK | MB_ICONERROR);

                    break;
                }

                default:
                    ActivateLayout(hwnd, LOWORD(wParam));
                    break;
            }
            break;

        case WM_DESTROY:
            DestroyMenu(hPopupMenu);
            DelTrayIcon(hwnd);
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, Message, wParam, lParam);
}

INT WINAPI
_tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpCmdLine, INT nCmdShow)
{
    WNDCLASS WndClass = {0};
    MSG msg;
    HANDLE hMutex;

    hMutex = CreateMutex(NULL, FALSE, szKbSwitcherName);
    if ((!hMutex) || (GetLastError() == ERROR_ALREADY_EXISTS))
        return 1;

    hInst = hInstance;
    hProcessHeap = GetProcessHeap();

    WndClass.style = 0;
    WndClass.lpfnWndProc   = (WNDPROC)WndProc;
    WndClass.cbClsExtra    = 0;
    WndClass.cbWndExtra    = 0;
    WndClass.hInstance     = hInstance;
    WndClass.hIcon         = NULL;
    WndClass.hCursor       = NULL;
    WndClass.hbrBackground = NULL;
    WndClass.lpszMenuName  = NULL;
    WndClass.lpszClassName = szKbSwitcherName;

    if (!RegisterClass(&WndClass))
        return 1;

    CreateWindow(szKbSwitcherName, NULL, 0, 0, 0, 1, 1, HWND_DESKTOP, NULL, hInstance, NULL);

    while(GetMessage(&msg,NULL,0,0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    if (hMutex) CloseHandle(hMutex);

    return 0;
}
