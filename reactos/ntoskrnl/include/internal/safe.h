#ifndef __NTOSKRNL_INCLUDE_INTERNAL_SAFE_H
#define __NTOSKRNL_INCLUDE_INTERNAL_SAFE_H

#ifndef AS_INVOKED

NTSTATUS MmSafeCopyFromUser(PVOID Dest, PVOID Src, ULONG NumberOfBytes);
NTSTATUS MmSafeCopyToUser(PVOID Dest, PVOID Src, ULONG NumberOfBytes);

NTSTATUS STDCALL
MmCopyFromCaller(PVOID Dest, PVOID Src, ULONG NumberOfBytes);
NTSTATUS STDCALL
MmCopyToCaller(PVOID Dest, PVOID Src, ULONG NumberOfBytes);

NTSTATUS
RtlCaptureUnicodeString(PUNICODE_STRING Dest,
			PUNICODE_STRING UnsafeSrc);

#endif /* !AS_INVOKED */

#endif /* __NTOSKRNL_INCLUDE_INTERNAL_SAFE_Hb */
