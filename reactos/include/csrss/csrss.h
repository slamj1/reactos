#ifndef __INCLUDE_CSRSS_CSRSS_H
#define __INCLUDE_CSRSS_CSRSS_H

#define NTOS_USER_MODE
#include <ntos.h>

#define CSR_PRIORITY_CLASS_NORMAL	(0x10)
#define CSR_PRIORITY_CLASS_IDLE		(0x20)
#define CSR_PRIORITY_CLASS_HIGH		(0x40)
#define CSR_PRIORITY_CLASS_REALTIME	(0x80)

#define CSR_CSRSS_SECTION_SIZE          (65536)

typedef struct
{
} CSRSS_CONNECT_PROCESS_REQUEST, PCSRSS_CONNECT_PROCESS_REQUEST;

typedef struct
{
} CSRSS_CONNECT_PROCESS_REPLY, PCSRSS_CONNECT_PROCESS_REPLY;

typedef struct
{
   ULONG NewProcessId;
   ULONG Flags;
} CSRSS_CREATE_PROCESS_REQUEST, *PCSRSS_CREATE_PROCESS_REQUEST;

typedef struct
{
   HANDLE InputHandle;
   HANDLE OutputHandle;
} CSRSS_CREATE_PROCESS_REPLY, *PCSRSS_CREATE_PROCESS_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   ULONG NrCharactersToWrite;
   BYTE Buffer[1];
} CSRSS_WRITE_CONSOLE_REQUEST, *PCSRSS_WRITE_CONSOLE_REQUEST;

typedef struct
{
   ULONG NrCharactersWritten;
} CSRSS_WRITE_CONSOLE_REPLY, *PCSRSS_WRITE_CONSOLE_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   WORD NrCharactersToRead;
   WORD nCharsCanBeDeleted;     // number of chars already in buffer that can be backspaced
} CSRSS_READ_CONSOLE_REQUEST, *PCSRSS_READ_CONSOLE_REQUEST;

typedef struct
{
   HANDLE EventHandle;
   ULONG NrCharactersRead;
   BYTE Buffer[1];
} CSRSS_READ_CONSOLE_REPLY, *PCSRSS_READ_CONSOLE_REPLY;

typedef struct
{
   HANDLE InputHandle;
   HANDLE OutputHandle;
} CSRSS_ALLOC_CONSOLE_REPLY, *PCSRSS_ALLOC_CONSOLE_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
} CSRSS_SCREEN_BUFFER_INFO_REQUEST, *PCSRSS_SCREEN_BUFFER_INFO_REQUEST;

typedef struct
{
   CONSOLE_SCREEN_BUFFER_INFO Info;
} CSRSS_SCREEN_BUFFER_INFO_REPLY, *PCSRSS_SCREEN_BUFFER_INFO_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   COORD Position;
} CSRSS_SET_CURSOR_REQUEST, *PCSRSS_SET_CURSOR_REQUEST;

typedef struct
{
   HANDLE ConsoleHandle;
   CHAR Char;
   COORD Position;
   WORD Length;
} CSRSS_FILL_OUTPUT_REQUEST, *PCSRSS_FILL_OUTPUT_REQUEST;

typedef struct
{
   HANDLE ConsoleHandle;
   CHAR Attribute;
   COORD Coord;
   WORD Length;
} CSRSS_FILL_OUTPUT_ATTRIB_REQUEST, *PCSRSS_FILL_OUTPUT_ATTRIB_REQUEST;

typedef struct
{
   HANDLE ConsoleHandle;
} CSRSS_READ_INPUT_REQUEST, *PCSRSS_READ_INPUT_REQUEST;

typedef struct
{
   INPUT_RECORD Input;
   BOOL MoreEvents;
   HANDLE Event;
} CSRSS_READ_INPUT_REPLY, *PCSRSS_READ_INPUT_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   WORD Length;
   COORD Coord;
   CHAR String[1];
} CSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REQUEST, *PCSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REQUEST;

typedef struct
{
   COORD EndCoord;
} CSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REPLY, *PCSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   WORD Length;
   COORD Coord;
   CHAR String[1];
} CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REQUEST, *PCSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REQUEST;

typedef struct
{
   COORD EndCoord;
} CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REPLY, *PCSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
} CSRSS_GET_CURSOR_INFO_REQUEST, *PCSRSS_GET_CURSOR_INFO_REQUEST;

typedef struct
{
   CONSOLE_CURSOR_INFO Info;
} CSRSS_GET_CURSOR_INFO_REPLY, *PCSRSS_GET_CURSOR_INFO_REPLY;

typedef struct
{
   HANDLE ConsoleHandle;
   CONSOLE_CURSOR_INFO Info;
} CSRSS_SET_CURSOR_INFO_REQUEST, *PCSRSS_SET_CURSOR_INFO_REQUEST;

typedef struct
{
   HANDLE ConsoleHandle;
   CHAR Attrib;
} CSRSS_SET_ATTRIB_REQUEST, *PCSRSS_SET_ATTRIB_REQUEST;

typedef struct
{
  HANDLE ConsoleHandle;
  DWORD Mode;
} CSRSS_SET_CONSOLE_MODE_REQUEST, *PCSRSS_SET_CONSOLE_MODE_REQUEST;

typedef struct
{
  HANDLE ConsoleHandle;
} CSRSS_GET_CONSOLE_MODE_REQUEST, *PCSRSS_GET_CONSOLE_MODE_REQUEST;

typedef struct
{
  DWORD ConsoleMode;
} CSRSS_GET_CONSOLE_MODE_REPLY, *PCSRSS_GET_CONSOLE_MODE_REPLY;

typedef struct
{
  /* may want to add some parameters here someday */
} CSRSS_CREATE_SCREEN_BUFFER_REQUEST, *PCSRSS_CREATE_SCREEN_BUFFER_REQUEST;

typedef struct
{
   HANDLE OutputHandle;  /* handle to newly created screen buffer */
} CSRSS_CREATE_SCREEN_BUFFER_REPLY, *PCSRSS_CREATE_SCREEN_BUFFER_REPLY;

typedef struct
{
   HANDLE OutputHandle;  /* handle to screen buffer to switch to */
} CSRSS_SET_ACTIVE_SCREEN_BUFFER_REQUEST, *PCSRSS_SET_ACTIVE_SCREEN_BUFFER_REQUEST;

typedef struct
{
	HANDLE	UniqueThread;
} CSRSS_IDENTIFY_ALERTABLE_THREAD_REQUEST, * PCSRSS_IDENTIFY_ALERTABLE_THREAD_REQUEST;

typedef struct
{
	CLIENT_ID	Cid;
} CSRSS_IDENTIFY_ALERTABLE_THREAD_REPLY, * PCSRSS_IDENTIFY_ALERTABLE_THREAD_REPLY;

typedef struct
{
  HANDLE Console;
  DWORD Length;
  WCHAR Title[1];
} CSRSS_SET_TITLE_REQUEST, *PCSRSS_SET_TITLE_REQUEST;

typedef struct
{
   HANDLE ConsoleHandle;
} CSRSS_GET_TITLE_REQUEST, *PCSRSS_GET_TITLE_REQUEST;

typedef struct
{
  HANDLE ConsoleHandle;
  DWORD Length;
  WCHAR Title[1];
} CSRSS_GET_TITLE_REPLY, *PCSRSS_GET_TITLE_REPLY;

typedef struct
{
  HANDLE ConsoleHandle;
  COORD BufferSize;
  COORD BufferCoord;
  SMALL_RECT WriteRegion;
  CHAR_INFO* CharInfo;
} CSRSS_WRITE_CONSOLE_OUTPUT_REQUEST, *PCSRSS_WRITE_CONSOLE_OUTPUT_REQUEST;

typedef struct
{
  SMALL_RECT WriteRegion;
} CSRSS_WRITE_CONSOLE_OUTPUT_REPLY, *PCSRSS_WRITE_CONSOLE_OUTPUT_REPLY;

typedef struct
{
   HANDLE ConsoleInput;
} CSRSS_FLUSH_INPUT_BUFFER_REQUEST, *PCSRSS_FLUSH_INPUT_BUFFER_REQUEST;

typedef struct
{
  HANDLE     ConsoleHandle;
  SMALL_RECT ScrollRectangle;
  BOOLEAN    UseClipRectangle;
  SMALL_RECT ClipRectangle;
  COORD      DestinationOrigin;
  CHAR_INFO  Fill;
} CSRSS_SCROLL_CONSOLE_SCREEN_BUFFER_REQUEST, *PCSRSS_SCROLL_CONSOLE_SCREEN_BUFFER_REQUEST;

typedef struct
{
  HANDLE ConsoleHandle;
  DWORD NumCharsToRead;
  COORD ReadCoord;
}CSRSS_READ_CONSOLE_OUTPUT_CHAR_REQUEST, *PCSRSS_READ_CONSOLE_OUTPUT_CHAR_REQUEST;

typedef struct
{
  COORD EndCoord;
  CHAR String[1];
}CSRSS_READ_CONSOLE_OUTPUT_CHAR_REPLY, *PCSRSS_READ_CONSOLE_OUTPUT_CHAR_REPLY;


#define CSRSS_MAX_WRITE_CONSOLE_REQUEST       \
      (MAX_MESSAGE_DATA - sizeof(ULONG) - sizeof(CSRSS_WRITE_CONSOLE_REQUEST))

#define CSRSS_MAX_SET_TITLE_REQUEST           (MAX_MESSAGE_DATA - sizeof( HANDLE ) - sizeof( DWORD ) - sizeof( ULONG ) - sizeof( LPC_MESSAGE ))

#define CSRSS_MAX_WRITE_CONSOLE_OUTPUT_CHAR   (MAX_MESSAGE_DATA - sizeof( ULONG ) - sizeof( CSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REQUEST ))

#define CSRSS_MAX_WRITE_CONSOLE_OUTPUT_ATTRIB   ((MAX_MESSAGE_DATA - sizeof( ULONG ) - sizeof( CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REQUEST )) / 2)

#define CSRSS_MAX_READ_CONSOLE_REQUEST        (MAX_MESSAGE_DATA - sizeof( ULONG ) - sizeof( CSRSS_READ_CONSOLE_REQUEST ))

#define CSRSS_MAX_READ_CONSOLE_OUTPUT_CHAR    (MAX_MESSAGE_DATA - sizeof(ULONG) - sizeof(HANDLE) - sizeof(DWORD) - sizeof(CSRSS_READ_CONSOLE_OUTPUT_CHAR_REQUEST))

// FIXME: it should be 80. Is this a limit due to LPC msg size?
#define CSRSS_MAX_TITLE_LENGTH          50

#define CSRSS_CREATE_PROCESS                (0x0)
#define CSRSS_TERMINATE_PROCESS             (0x1)
#define CSRSS_WRITE_CONSOLE                 (0x2)
#define CSRSS_READ_CONSOLE                  (0x3)
#define CSRSS_ALLOC_CONSOLE                 (0x4)
#define CSRSS_FREE_CONSOLE                  (0x5)
#define CSRSS_CONNECT_PROCESS               (0x6)
#define CSRSS_SCREEN_BUFFER_INFO            (0x7)
#define CSRSS_SET_CURSOR                    (0x8)
#define CSRSS_FILL_OUTPUT                   (0x9)
#define CSRSS_READ_INPUT                    (0xA)
#define CSRSS_WRITE_CONSOLE_OUTPUT_CHAR     (0xB)
#define CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB   (0xC)
#define CSRSS_FILL_OUTPUT_ATTRIB            (0xD)
#define CSRSS_GET_CURSOR_INFO               (0xE)
#define CSRSS_SET_CURSOR_INFO               (0xF)
#define CSRSS_SET_ATTRIB                    (0x10)
#define CSRSS_GET_MODE                      (0x11)
#define CSRSS_SET_MODE                      (0x12)
#define CSRSS_CREATE_SCREEN_BUFFER          (0x13)
#define CSRSS_SET_SCREEN_BUFFER             (0x14)
#define CSRSS_SET_TITLE                     (0x15)
#define CSRSS_GET_TITLE                     (0x16)
#define CSRSS_WRITE_CONSOLE_OUTPUT          (0x17)
#define CSRSS_FLUSH_INPUT_BUFFER            (0x18)
#define CSRSS_SCROLL_CONSOLE_SCREEN_BUFFER  (0x19)
#define CSRSS_READ_CONSOLE_OUTPUT_CHAR      (0x1A)


/* Keep in sync with definition below. */
#define CSRSS_REQUEST_HEADER_SIZE (sizeof(LPC_MESSAGE) + sizeof(ULONG))

typedef struct
{
  LPC_MESSAGE Header;
  ULONG Type;
  union
  {
    CSRSS_CREATE_PROCESS_REQUEST CreateProcessRequest;
    CSRSS_CONNECT_PROCESS_REQUEST ConnectRequest;
    CSRSS_WRITE_CONSOLE_REQUEST WriteConsoleRequest;
    CSRSS_READ_CONSOLE_REQUEST ReadConsoleRequest;
    CSRSS_SCREEN_BUFFER_INFO_REQUEST ScreenBufferInfoRequest;
    CSRSS_SET_CURSOR_REQUEST SetCursorRequest;
    CSRSS_FILL_OUTPUT_REQUEST FillOutputRequest;
    CSRSS_READ_INPUT_REQUEST ReadInputRequest;
    CSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REQUEST WriteConsoleOutputCharRequest;
    CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REQUEST WriteConsoleOutputAttribRequest;
    CSRSS_FILL_OUTPUT_ATTRIB_REQUEST FillOutputAttribRequest;
    CSRSS_SET_CURSOR_INFO_REQUEST SetCursorInfoRequest;
    CSRSS_GET_CURSOR_INFO_REQUEST GetCursorInfoRequest;
    CSRSS_SET_ATTRIB_REQUEST SetAttribRequest;
    CSRSS_SET_CONSOLE_MODE_REQUEST SetConsoleModeRequest;
    CSRSS_GET_CONSOLE_MODE_REQUEST GetConsoleModeRequest;
    CSRSS_CREATE_SCREEN_BUFFER_REQUEST CreateScreenBufferRequest;
    CSRSS_SET_ACTIVE_SCREEN_BUFFER_REQUEST SetActiveScreenBufferRequest;
    CSRSS_SET_TITLE_REQUEST SetTitleRequest;
    CSRSS_GET_TITLE_REQUEST GetTitleRequest;
    CSRSS_WRITE_CONSOLE_OUTPUT_REQUEST WriteConsoleOutputRequest;
    CSRSS_FLUSH_INPUT_BUFFER_REQUEST FlushInputBufferRequest;
    CSRSS_SCROLL_CONSOLE_SCREEN_BUFFER_REQUEST 
    ScrollConsoleScreenBufferRequest;
    CSRSS_READ_CONSOLE_OUTPUT_CHAR_REQUEST ReadConsoleOutputCharRequest;
  } Data;
} CSRSS_API_REQUEST, *PCSRSS_API_REQUEST;

typedef struct
{
  LPC_MESSAGE Header;
  NTSTATUS Status;
  union
  {
    CSRSS_CREATE_PROCESS_REPLY CreateProcessReply;
    CSRSS_CONNECT_PROCESS_REPLY ConnectReply;
    CSRSS_WRITE_CONSOLE_REPLY WriteConsoleReply;
    CSRSS_READ_CONSOLE_REPLY ReadConsoleReply;
    CSRSS_ALLOC_CONSOLE_REPLY AllocConsoleReply;
    CSRSS_SCREEN_BUFFER_INFO_REPLY ScreenBufferInfoReply;
    CSRSS_READ_INPUT_REPLY ReadInputReply;
    CSRSS_WRITE_CONSOLE_OUTPUT_CHAR_REPLY WriteConsoleOutputCharReply;
    CSRSS_WRITE_CONSOLE_OUTPUT_ATTRIB_REPLY WriteConsoleOutputAttribReply;
    CSRSS_GET_CURSOR_INFO_REPLY GetCursorInfoReply;
    CSRSS_GET_CONSOLE_MODE_REPLY GetConsoleModeReply;
    CSRSS_CREATE_SCREEN_BUFFER_REPLY CreateScreenBufferReply;
    CSRSS_GET_TITLE_REPLY GetTitleReply;
    CSRSS_WRITE_CONSOLE_OUTPUT_REPLY WriteConsoleOutputReply;
    CSRSS_READ_CONSOLE_OUTPUT_CHAR_REPLY ReadConsoleOutputCharReply;
  } Data;
} CSRSS_API_REPLY, *PCSRSS_API_REPLY;

#endif /* __INCLUDE_CSRSS_CSRSS_H */
