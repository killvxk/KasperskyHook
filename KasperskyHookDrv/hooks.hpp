#pragma once

#include <ntifs.h>
#include <windef.h>

//
// Function typedefs.
//
using f_NtCreateFile = NTSTATUS( * )
(
	PHANDLE            FileHandle,
	ACCESS_MASK        DesiredAccess,
	POBJECT_ATTRIBUTES ObjectAttributes,
	PIO_STATUS_BLOCK   IoStatusBlock,
	PLARGE_INTEGER     AllocationSize,
	ULONG              FileAttributes,
	ULONG              ShareAccess,
	ULONG              CreateDisposition,
	ULONG              CreateOptions,
	PVOID              EaBuffer,
	ULONG              EaLength
);

//
// Functions (hooks).
//
namespace hooks
{
	NTSTATUS hk_NtCreateFile
	(
		PHANDLE            FileHandle,
		ACCESS_MASK        DesiredAccess,
		POBJECT_ATTRIBUTES ObjectAttributes,
		PIO_STATUS_BLOCK   IoStatusBlock,
		PLARGE_INTEGER     AllocationSize,
		ULONG              FileAttributes,
		ULONG              ShareAccess,
		ULONG              CreateDisposition,
		ULONG              CreateOptions,
		PVOID              EaBuffer,
		ULONG              EaLength
	);
}

//
// Function pointers to original functions.
//
inline f_NtCreateFile o_NtCreateFile = nullptr;