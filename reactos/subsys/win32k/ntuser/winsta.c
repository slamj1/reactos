/* $Id: winsta.c,v 1.8 2002/09/07 15:13:12 chorns Exp $
 *
 * COPYRIGHT:        See COPYING in the top level directory
 * PROJECT:          ReactOS kernel
 * PURPOSE:          Window stations and desktops
 * FILE:             subsys/win32k/ntuser/winsta.c
 * PROGRAMER:        Casper S. Hornstrup (chorns@users.sourceforge.net)
 * REVISION HISTORY:
 *       06-06-2001  CSH  Created
 * NOTES:            Exported functions set the Win32 last error value
 *                   on errors. The value can be retrieved with the Win32
 *                   function GetLastError().
 * TODO:             The process window station is created on
 *                   the first USER32/GDI32 call not related
 *                   to window station/desktop handling
 */

/* INCLUDES ******************************************************************/

#define NTOS_KERNEL_MODE
#include <ntos.h>
#include <win32k/win32k.h>
#include <include/winsta.h>
#include <include/object.h>
#include <include/guicheck.h>
#include <include/class.h>
#include <include/window.h>

#define NDEBUG
#include <debug.h>

/* GLOBALS *******************************************************************/

#define WINSTA_ROOT_NAME L"\\Windows\\WindowStations"

LRESULT CALLBACK
W32kDesktopWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

STATIC PWNDCLASS_OBJECT DesktopWindowClass;

/* Currently active desktop */
STATIC HDESK InputDesktopHandle = NULL; 
STATIC PDESKTOP_OBJECT InputDesktop = NULL;
STATIC PWINSTATION_OBJECT InputWindowStation = NULL;

/* FUNCTIONS *****************************************************************/

PDESKTOP_OBJECT
W32kGetActiveDesktop(VOID)
{
  return(InputDesktop);
}

NTSTATUS
InitWindowStationImpl(VOID)
{
  OBJECT_ATTRIBUTES ObjectAttributes;
  HANDLE WindowStationsDirectory;
  UNICODE_STRING UnicodeString;
  NTSTATUS Status;
  WNDCLASSEX wcx;

  /*
   * Create the '\Windows\WindowStations' directory
   */
  RtlInitUnicodeStringFromLiteral(&UnicodeString,
		       WINSTA_ROOT_NAME);

  InitializeObjectAttributes(&ObjectAttributes,
			     &UnicodeString,
			     0,
			     NULL,
			     NULL);
  
  Status = ZwCreateDirectoryObject(&WindowStationsDirectory,
				   0,
				   &ObjectAttributes);
  if (!NT_SUCCESS(Status))
    {
      DPRINT("Could not create \\Windows\\WindowStations directory "
	     "(Status 0x%X)\n", Status);
      return Status;
    }

  /* 
   * Create the desktop window class
   */
  wcx.style = 0;
  wcx.lpfnWndProc = W32kDesktopWindowProc;
  wcx.cbClsExtra = wcx.cbWndExtra = 0;
  wcx.hInstance = wcx.hIcon = wcx.hCursor = NULL;
  wcx.hbrBackground = NULL;
  wcx.lpszMenuName = NULL;
  wcx.lpszClassName = L"DesktopWindowClass";
  DesktopWindowClass = W32kCreateClass(&wcx, TRUE);

  return(STATUS_SUCCESS);
}

NTSTATUS
CleanupWindowStationImpl(VOID)
{
  return STATUS_SUCCESS;
}


NTSTATUS
ValidateWindowStationHandle(HWINSTA WindowStation,
			    KPROCESSOR_MODE AccessMode,
			    ACCESS_MASK DesiredAccess,
			    PWINSTATION_OBJECT *Object)
{
  NTSTATUS Status;
  
  Status = ObReferenceObjectByHandle(WindowStation,
				     DesiredAccess,
				     ExWindowStationObjectType,
				     AccessMode,
				     (PVOID*)Object,
				     NULL);
  if (!NT_SUCCESS(Status)) 
    {
      SetLastNtError(Status);
    }
  
  return Status;
}

NTSTATUS
ValidateDesktopHandle(HDESK Desktop,
		      KPROCESSOR_MODE AccessMode,
		      ACCESS_MASK DesiredAccess,
		      PDESKTOP_OBJECT *Object)
{
  NTSTATUS Status;

  Status = ObReferenceObjectByHandle(Desktop,
				     DesiredAccess,
				     ExDesktopObjectType,
				     AccessMode,
				     (PVOID*)Object,
				     NULL);
  if (!NT_SUCCESS(Status)) 
    {
      SetLastNtError(Status);
    }
  
  return Status;
}

/*
 * FUNCTION:
 *   Closes a window station handle
 * ARGUMENTS:
 *   hWinSta = Handle to the window station 
 * RETURNS:
 *   Status
 * NOTES:
 *   The window station handle can be created with
 *   NtUserCreateWindowStation() or NtUserOpenWindowStation().
 *   Attemps to close a handle to the window station assigned
 *   to the calling process will fail
 */
BOOL
STDCALL
NtUserCloseWindowStation(
  HWINSTA hWinSta)
{
  PWINSTATION_OBJECT Object;
  NTSTATUS Status;

  DPRINT("About to close window station handle (0x%X)\n", hWinSta);

  Status = ValidateWindowStationHandle(
    hWinSta,
    KernelMode,
    0,
    &Object);
  if (!NT_SUCCESS(Status)) {
    DPRINT("Validation of window station handle (0x%X) failed\n", hWinSta);
    return FALSE;
  }

  ObDereferenceObject(Object);

  DPRINT("Closing window station handle (0x%X)\n", hWinSta);

  Status = ZwClose(hWinSta);
  if (!NT_SUCCESS(Status)) {
    SetLastNtError(Status);
    return FALSE;
  } else {
    return TRUE;
  }
}

/*
 * FUNCTION:
 *   Creates a new window station
 * ARGUMENTS:
 *   lpszWindowStationName = Name of the new window station
 *   dwDesiredAccess       = Requested type of access
 *   lpSecurity            = Security descriptor
 *   Unknown3              = Unused
 *   Unknown4              = Unused
 *   Unknown5              = Unused
 * RETURNS:
 *   Handle to the new window station that can be closed with
 *   NtUserCloseWindowStation()
 *   Zero on failure
 */
HWINSTA STDCALL
NtUserCreateWindowStation(PUNICODE_STRING lpszWindowStationName,
			  ACCESS_MASK dwDesiredAccess,
			  LPSECURITY_ATTRIBUTES lpSecurity,
			  DWORD Unknown3,
			  DWORD Unknown4,
			  DWORD Unknown5)
{
  OBJECT_ATTRIBUTES ObjectAttributes;
  UNICODE_STRING WindowStationName;
  PWINSTATION_OBJECT WinStaObject;
  WCHAR NameBuffer[MAX_PATH];
  NTSTATUS Status;
  HWINSTA WinSta;

  wcscpy(NameBuffer, WINSTA_ROOT_NAME);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, lpszWindowStationName->Buffer);
  RtlInitUnicodeString(&WindowStationName, NameBuffer);

  DPRINT("Trying to open window station (%wZ)\n", &WindowStationName);

  /* Initialize ObjectAttributes for the window station object */
  InitializeObjectAttributes(&ObjectAttributes,
			     &WindowStationName,
			     0,
			     NULL,
			     NULL);
  
  Status = ObOpenObjectByName(&ObjectAttributes,
			      ExWindowStationObjectType,
			      NULL,
			      UserMode,
			      dwDesiredAccess,
			      NULL,
			      &WinSta);
  if (NT_SUCCESS(Status))
    {
      DPRINT("Successfully opened window station (%wZ)\n", WindowStationName);
      return((HWINSTA)WinSta);
    }
  
  DPRINT("Creating window station (%wZ)\n", &WindowStationName);

  Status = ObRosCreateObject(&WinSta,
			  STANDARD_RIGHTS_REQUIRED,
			  &ObjectAttributes,
			  ExWindowStationObjectType,
			  (PVOID*)&WinStaObject);
  if (!NT_SUCCESS(Status))
    {
      DPRINT("Failed creating window station (%wZ)\n", &WindowStationName);
      SetLastNtError(STATUS_INSUFFICIENT_RESOURCES);
      return (HWINSTA)0;
    }

  WinStaObject->HandleTable = ObmCreateHandleTable();
  if (!WinStaObject->HandleTable)
    {
      DPRINT("Failed creating handle table\n");
      ObDereferenceObject(WinStaObject);
      SetLastNtError(STATUS_INSUFFICIENT_RESOURCES);
      return((HWINSTA)0);
    }
  
  DPRINT("Window station successfully created (%wZ)\n", &WindowStationName);
  
  return((HWINSTA)WinSta);
}

BOOL
STDCALL
NtUserGetObjectInformation(
  HANDLE hObject,
  DWORD nIndex,
  PVOID pvInformation,
  DWORD nLength,
  PDWORD nLengthNeeded)
{
  return FALSE;
}

/*
 * FUNCTION:
 *   Returns a handle to the current process window station
 * ARGUMENTS:
 *   None
 * RETURNS:
 *   Handle to the window station assigned to the current process
 *   Zero on failure
 * NOTES:
 *   The handle need not be closed by the caller
 */
HWINSTA
STDCALL
NtUserGetProcessWindowStation(VOID)
{
  return PROCESS_WINDOW_STATION();
}

BOOL
STDCALL
NtUserLockWindowStation(
  HWINSTA hWindowStation)
{
  UNIMPLEMENTED

  return 0;
}

/*
 * FUNCTION:
 *   Opens an existing window station
 * ARGUMENTS:
 *   lpszWindowStationName = Name of the existing window station
 *   dwDesiredAccess       = Requested type of access
 * RETURNS:
 *   Handle to the window station
 *   Zero on failure
 * NOTES:
 *   The returned handle can be closed with NtUserCloseWindowStation()
 */
HWINSTA
STDCALL
NtUserOpenWindowStation(
  PUNICODE_STRING lpszWindowStationName,
  ACCESS_MASK dwDesiredAccess)
{
  OBJECT_ATTRIBUTES ObjectAttributes;
  UNICODE_STRING WindowStationName;
  PWINSTATION_OBJECT WinStaObject;
  WCHAR NameBuffer[MAX_PATH];
  NTSTATUS Status;
  HWINSTA WinSta;

  wcscpy(NameBuffer, WINSTA_ROOT_NAME);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, lpszWindowStationName->Buffer);
  RtlInitUnicodeString(&WindowStationName, NameBuffer);

  DPRINT("Trying to open window station (%wZ)\n", &WindowStationName);

  /* Initialize ObjectAttributes for the window station object */
  InitializeObjectAttributes(
    &ObjectAttributes,
    &WindowStationName,
    0,
    NULL,
    NULL);

  Status = ObOpenObjectByName(
    &ObjectAttributes,
    ExDesktopObjectType,
    NULL,
    UserMode,
    dwDesiredAccess,
    NULL,
    &WinSta);
  if (NT_SUCCESS(Status))
  {
    DPRINT("Successfully opened window station (%wZ)\n", &WindowStationName);
    return (HWINSTA)WinSta;
  }

  SetLastNtError(Status);
  return (HWINSTA)0;
}

BOOL
STDCALL
NtUserSetObjectInformation(
  HANDLE hObject,
  DWORD nIndex,
  PVOID pvInformation,
  DWORD nLength)
{
  /* FIXME: ZwQueryObject */
  /* FIXME: ZwSetInformationObject */
  SetLastNtError(STATUS_UNSUCCESSFUL);
  return FALSE;
}

/*
 * FUNCTION:
 *   Assigns a window station to the current process
 * ARGUMENTS:
 *   hWinSta = Handle to the window station
 * RETURNS:
 *   Status
 */
BOOL STDCALL
NtUserSetProcessWindowStation(HWINSTA hWindowStation)
{
  PWINSTATION_OBJECT Object;
  NTSTATUS Status;

  DPRINT("About to set process window station with handle (0x%X)\n", 
	 hWindowStation);

  Status = ValidateWindowStationHandle(hWindowStation,
				       KernelMode,
				       0,
				       &Object);
  if (!NT_SUCCESS(Status)) 
    {
      DPRINT("Validation of window station handle (0x%X) failed\n", 
	     hWindowStation);
      return FALSE;
    }
  
  ObDereferenceObject(Object);

  SET_PROCESS_WINDOW_STATION(hWindowStation);
  DPRINT("IoGetCurrentProcess()->Win32WindowStation 0x%X\n",
	 IoGetCurrentProcess()->Win32WindowStation);

  return TRUE;
}

DWORD
STDCALL
NtUserSetWindowStationUser(
  DWORD Unknown0,
  DWORD Unknown1,
  DWORD Unknown2,
  DWORD Unknown3)
{
  UNIMPLEMENTED

  return 0;
}

BOOL
STDCALL
NtUserUnlockWindowStation(
  HWINSTA hWindowStation)
{
  UNIMPLEMENTED

  return FALSE;
}


/*
 * FUNCTION:
 *   Closes a desktop handle
 * ARGUMENTS:
 *   hDesktop = Handle to the desktop
 * RETURNS:
 *   Status
 * NOTES:
 *   The desktop handle can be created with NtUserCreateDesktop() or
 *   NtUserOpenDesktop().
 *   The function will fail if any thread in the calling process is using the
 *   specified desktop handle or if the handle refers to the initial desktop
 *   of the calling process
 */
BOOL
STDCALL
NtUserCloseDesktop(
  HDESK hDesktop)
{
  PDESKTOP_OBJECT Object;
  NTSTATUS Status;

  DPRINT("About to close desktop handle (0x%X)\n", hDesktop);

  Status = ValidateDesktopHandle(
    hDesktop,
    KernelMode,
    0,
    &Object);
  if (!NT_SUCCESS(Status)) {
    DPRINT("Validation of desktop handle (0x%X) failed\n", hDesktop);
    return FALSE;
  }

  ObDereferenceObject(Object);

  DPRINT("Closing desktop handle (0x%X)\n", hDesktop);

  Status = ZwClose(hDesktop);
  if (!NT_SUCCESS(Status)) {
    SetLastNtError(Status);
    return FALSE;
  } else {
    return TRUE;
  }
}

/*
 * FUNCTION:
 *   Creates a new desktop
 * ARGUMENTS:
 *   lpszDesktopName = Name of the new desktop
 *   dwFlags         = Interaction flags
 *   dwDesiredAccess = Requested type of access
 *   lpSecurity      = Security descriptor
 *   hWindowStation  = Handle to window station on which to create the desktop
 * RETURNS:
 *   Handle to the new desktop that can be closed with NtUserCloseDesktop()
 *   Zero on failure
 */
HDESK STDCALL
NtUserCreateDesktop(PUNICODE_STRING lpszDesktopName,
		    DWORD dwFlags,
		    ACCESS_MASK dwDesiredAccess,
		    LPSECURITY_ATTRIBUTES lpSecurity,
		    HWINSTA hWindowStation)
{
  OBJECT_ATTRIBUTES ObjectAttributes;
  PWINSTATION_OBJECT WinStaObject;
  PDESKTOP_OBJECT DesktopObject;
  UNICODE_STRING DesktopName;
  WCHAR NameBuffer[MAX_PATH];
  NTSTATUS Status;
  HDESK Desktop;

  Status = ValidateWindowStationHandle(hWindowStation,
				       KernelMode,
				       0,
				       &WinStaObject);
  if (!NT_SUCCESS(Status))
    {
      DPRINT("Failed validation of window station handle (0x%X)\n", 
	     hWindowStation);
      return((HDESK)0);
    }
  
  wcscpy(NameBuffer, WINSTA_ROOT_NAME);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, WinStaObject->Name.Buffer);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, lpszDesktopName->Buffer);
  RtlInitUnicodeString(&DesktopName, NameBuffer);

  ObDereferenceObject(WinStaObject);

  DPRINT("Trying to open desktop (%wZ)\n", &DesktopName);

  /* Initialize ObjectAttributes for the desktop object */
  InitializeObjectAttributes(&ObjectAttributes,
			     &DesktopName,
			     0,
			     NULL,
			     NULL);
  Status = ObOpenObjectByName(&ObjectAttributes,
			      ExDesktopObjectType,
			      NULL,
			      UserMode,
			      dwDesiredAccess,
			      NULL,
			      &Desktop);
  if (NT_SUCCESS(Status))
    {
      DPRINT("Successfully opened desktop (%wZ)\n", &DesktopName);
      return((HDESK)Desktop);
    }

  DPRINT("Status for open operation (0x%X)\n", Status);

  Status = ObRosCreateObject(&Desktop,
			  STANDARD_RIGHTS_REQUIRED,
			  &ObjectAttributes,
			  ExDesktopObjectType,
			  (PVOID*)&DesktopObject);
  if (!NT_SUCCESS(Status))
    {
      DPRINT("Failed creating desktop (%wZ)\n", &DesktopName);
      SetLastNtError(STATUS_UNSUCCESSFUL);
      return((HDESK)0);
    }
  
  /* Initialize some local (to win32k) desktop state. */
  DesktopObject->ActiveMessageQueue = NULL;  
  InitializeListHead(&DesktopObject->WindowListHead);
  DesktopObject->DesktopWindow = 
    W32kCreateDesktopWindow(DesktopObject->WindowStation,
			    DesktopWindowClass,
			    640, 480);

  return((HDESK)Desktop);
}

HDESK STDCALL
NtUserGetThreadDesktop(DWORD dwThreadId,
		       DWORD Unknown1)
{
  UNIMPLEMENTED;
  return((HDESK)0);
}

/*
 * FUNCTION:
 *   Opens an existing desktop
 * ARGUMENTS:
 *   lpszDesktopName = Name of the existing desktop
 *   dwFlags         = Interaction flags
 *   dwDesiredAccess = Requested type of access
 * RETURNS:
 *   Handle to the desktop
 *   Zero on failure
 * NOTES:
 *   The returned handle can be closed with NtUserCloseDesktop()
 */
HDESK
STDCALL
NtUserOpenDesktop(
  PUNICODE_STRING lpszDesktopName,
  DWORD dwFlags,
  ACCESS_MASK dwDesiredAccess)
{
  OBJECT_ATTRIBUTES ObjectAttributes;
  PWINSTATION_OBJECT WinStaObject;
  UNICODE_STRING DesktopName;
  WCHAR NameBuffer[MAX_PATH];
  NTSTATUS Status;
  HDESK Desktop;

  /* Validate the window station handle and
     compose the fully qualified desktop name */

  Status = ValidateWindowStationHandle(
    PROCESS_WINDOW_STATION(),
    KernelMode,
    0,
    &WinStaObject);
  if (!NT_SUCCESS(Status))
  {
    DPRINT("Failed validation of window station handle (0x%X)\n",
      PROCESS_WINDOW_STATION());
    return (HDESK)0;
  }

  wcscpy(NameBuffer, WINSTA_ROOT_NAME);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, WinStaObject->Name.Buffer);
  wcscat(NameBuffer, L"\\");
  wcscat(NameBuffer, lpszDesktopName->Buffer);
  RtlInitUnicodeString(&DesktopName, NameBuffer);

  ObDereferenceObject(WinStaObject);


  DPRINT("Trying to open desktop station (%wZ)\n", &DesktopName);

  /* Initialize ObjectAttributes for the desktop object */
  InitializeObjectAttributes(
    &ObjectAttributes,
    &DesktopName,
    0,
    NULL,
    NULL);

  Status = ObOpenObjectByName(
    &ObjectAttributes,
    ExDesktopObjectType,
    NULL,
    UserMode,
    dwDesiredAccess,
    NULL,
    &Desktop);
  if (NT_SUCCESS(Status))
  {
    DPRINT("Successfully opened desktop (%wZ)\n", &DesktopName);
    return (HDESK)Desktop;
  }

  SetLastNtError(Status);
  return (HDESK)0;
}

/*
 * FUNCTION:
 *   Opens the input (interactive) desktop
 * ARGUMENTS:
 *   dwFlags         = Interaction flags
 *   fInherit        = Inheritance option
 *   dwDesiredAccess = Requested type of access
 * RETURNS:
 *   Handle to the input desktop
 *   Zero on failure
 * NOTES:
 *   The returned handle can be closed with NtUserCloseDesktop()
 */
HDESK
STDCALL
NtUserOpenInputDesktop(
  DWORD dwFlags,
  BOOL fInherit,
  ACCESS_MASK dwDesiredAccess)
{
  PDESKTOP_OBJECT Object;
  NTSTATUS Status;
  HDESK Desktop;

  DPRINT("About to open input desktop\n");

  /* Get a pointer to the desktop object */

  Status = ValidateDesktopHandle(
    InputDesktop,
    KernelMode,
    0,
    &Object);
  if (!NT_SUCCESS(Status)) {
    DPRINT("Validation of input desktop handle (0x%X) failed\n", InputDesktop);
    return (HDESK)0;
  }

  /* Create a new handle to the object */

  Status = ObOpenObjectByPointer(
    Object,
    0,
    NULL,
    dwDesiredAccess,
    ExDesktopObjectType,
    UserMode,
    &Desktop);

  ObDereferenceObject(Object);

  if (NT_SUCCESS(Status))
  {
    DPRINT("Successfully opened input desktop\n");
    return (HDESK)Desktop;
  }

  SetLastNtError(Status);
  return (HDESK)0;
}

BOOL STDCALL
NtUserPaintDesktop(HDC hDC)
{
  UNIMPLEMENTED

  return FALSE;
}

DWORD STDCALL
NtUserResolveDesktopForWOW(DWORD Unknown0)
{
  UNIMPLEMENTED
  return 0;
}

BOOL STDCALL
NtUserSetThreadDesktop(HDESK hDesktop)
{  
  PDESKTOP_OBJECT DesktopObject;
  NTSTATUS Status;

  /* Initialize the Win32 state if necessary. */
  W32kGuiCheck();

  /* Validate the new desktop. */
  Status = ValidateDesktopHandle(hDesktop,
				 KernelMode,
				 0,
				 &DesktopObject);
  if (!NT_SUCCESS(Status)) 
    {
      DPRINT("Validation of desktop handle (0x%X) failed\n", hDesktop);
      return(FALSE);
    }

  /* Check for setting the same desktop as before. */
  if (DesktopObject == PsGetWin32Thread()->Desktop)
    {
      ObDereferenceObject(DesktopObject);
      return(TRUE);
    }

  /* FIXME: Should check here to see if the thread has any windows. */

  ObDereferenceObject(PsGetWin32Thread()->Desktop);
  PsGetWin32Thread()->Desktop = DesktopObject;

  return(TRUE);
}

/*
 * FUNCTION:
 *   Sets the current input (interactive) desktop
 * ARGUMENTS:
 *   hDesktop = Handle to desktop
 * RETURNS:
 *   Status
 */
BOOL STDCALL
NtUserSwitchDesktop(HDESK hDesktop)
{
  PDESKTOP_OBJECT DesktopObject;
  NTSTATUS Status;

  DPRINT("About to switch desktop (0x%X)\n", hDesktop);

  Status = ValidateDesktopHandle(hDesktop,
				 KernelMode,
				 0,
				 &DesktopObject);
  if (!NT_SUCCESS(Status)) 
    {
      DPRINT("Validation of desktop handle (0x%X) failed\n", hDesktop);
      return(FALSE);
    }

  /* FIXME: Fail if the desktop belong to an invisible window station */
  /* FIXME: Fail if the process is associated with a secured
            desktop such as Winlogon or Screen-Saver */
  /* FIXME: Connect to input device */

  /* Set the active desktop in the desktop's window station. */
  DesktopObject->WindowStation->ActiveDesktop = DesktopObject;

  /* Set the global state. */
  InputDesktopHandle = hDesktop;
  InputDesktop = DesktopObject;
  InputWindowStation = DesktopObject->WindowStation;

  ObDereferenceObject(DesktopObject);

  return(TRUE);
}

LRESULT CALLBACK
W32kDesktopWindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
    {
    case WM_CREATE:
      return(0);

    case WM_NCCREATE:
      return(1);

    default:
      return(0);
    }
}

/* EOF */
