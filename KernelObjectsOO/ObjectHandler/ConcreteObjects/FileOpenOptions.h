#pragma once
#include "../../targetver.h"
#include <windows.h>
//#include <winternl.h>

/*
In this class I want to create a status descriptor of the File Open Option it has been created with
Also create a factory class to generate this kind of this class*/
namespace OOK
{
	class FileOpenOptions
	{
	public:
		enum class FileType
		{
			DirectoryFile = FILE_DIRECTORY_FILE,
			NonDirectoryFile = FILE_NON_DIRECTORY_FILE,
		};

		enum class FileSync
		{
			SyncIOAlert = FILE_SYNCHRONOUS_IO_ALERT,		//DesiredAccess SYNCHRONIZE must be on
			SyncIONonAlert = FILE_SYNCHRONOUS_IO_NONALERT,	//DesiredAccess SYNCHRONIZE must be on

			ReserveOPFilter = FILE_RESERVE_OPFILTER,			//Try to lock the file! will return -> STATUS_OPLOCK_NOT_GRANTED if not succedded (already locked)
			CompleteIfOplocked = FILE_COMPLETE_IF_OPLOCKED,		//Will not wait for the lock to free. Will return -> STATUS_OPLOCK_NOT_GRANTED if not succedded
			OpenRequiringOplock = FILE_OPEN_REQUIRING_OPLOCK
		};

		enum class FileAccessMethod
		{
			NoIntermidiateBuffering = FILE_NO_INTERMEDIATE_BUFFERING,	//if FILE_NO_INTERMEDIATE _BUFFERING on -> FILE_WRITE_THROUGH is on! ++ does not work with DesiredAccess parameter's FILE_APPEND_DATA 
			WriteThrough = FILE_WRITE_THROUGH,
			SequentialOnly = FILE_SEQUENTIAL_ONLY,
			RandomAccess = FILE_RANDOM_ACCESS
		};

		enum class OnOpen
		{
		#if WINVER >= _WIN32_WINNT_WIN8
			//fileSessionAware = FILE_SESSION_AWARE,
		#endif
			OpenByFileID = FILE_OPEN_BY_FILE_ID,
			ReparsePoint = FILE_OPEN_REPARSE_POINT,
			NoRecall = FILE_OPEN_NO_RECALL,
			ForFreeSpaceQuery = FILE_OPEN_FOR_FREE_SPACE_QUERY,
			RemoteInstance = FILE_OPEN_REMOTE_INSTANCE,
			ForBackupIntent = FILE_OPEN_FOR_BACKUP_INTENT
		};

		enum class OnClose
		{
			DeleteOnClose = FILE_DELETE_ON_CLOSE
		};

		//FILE_SESSION_AWARE


	};
}

/*

//
// Define the create/open option flags
//

#define FILE_DIRECTORY_FILE                     0x00000001
#define FILE_WRITE_THROUGH                      0x00000002
#define FILE_SEQUENTIAL_ONLY                    0x00000004
#define FILE_NO_INTERMEDIATE_BUFFERING          0x00000008

#define FILE_SYNCHRONOUS_IO_ALERT               0x00000010
#define FILE_SYNCHRONOUS_IO_NONALERT            0x00000020
#define FILE_NON_DIRECTORY_FILE                 0x00000040
#define FILE_CREATE_TREE_CONNECTION             0x00000080	//TODO WTF does this flag mean?!

#define FILE_COMPLETE_IF_OPLOCKED               0x00000100
#define FILE_NO_EA_KNOWLEDGE                    0x00000200
#define FILE_OPEN_REMOTE_INSTANCE               0x00000400
#define FILE_RANDOM_ACCESS                      0x00000800

#define FILE_DELETE_ON_CLOSE                    0x00001000
#define FILE_OPEN_BY_FILE_ID                    0x00002000
#define FILE_OPEN_FOR_BACKUP_INTENT             0x00004000
#define FILE_NO_COMPRESSION                     0x00008000

#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#define FILE_OPEN_REQUIRING_OPLOCK              0x00010000
#endif

#define FILE_RESERVE_OPFILTER                   0x00100000
#define FILE_OPEN_REPARSE_POINT                 0x00200000
#define FILE_OPEN_NO_RECALL                     0x00400000
#define FILE_OPEN_FOR_FREE_SPACE_QUERY          0x00800000

#define FILE_VALID_OPTION_FLAGS                 0x00ffffff
#define FILE_VALID_PIPE_OPTION_FLAGS            0x00000032
#define FILE_VALID_MAILSLOT_OPTION_FLAGS        0x00000032
#define FILE_VALID_SET_FLAGS                    0x00000036



FILE_DIRECTORY_FILE
The file being created or opened is a directory file. With this flag, the CreateDisposition parameter must be set to FILE_CREATE, FILE_OPEN, or FILE_OPEN_IF. With this flag, other compatible CreateOptions flags include only the following: FILE_SYNCHRONOUS_IO_ALERT, FILE_SYNCHRONOUS_IO _NONALERT, FILE_WRITE_THROUGH, FILE_OPEN_FOR_BACKUP_INTENT, and FILE_OPEN_BY_FILE_ID.
FILE_NON_DIRECTORY_FILE
The file being opened must not be a directory file or this call fails. The file object being opened can represent a data file, a logical, virtual, or physical device, or a volume.
FILE_WRITE_THROUGH
Applications that write data to the file must actually transfer the data into the file before any requested write operation is considered complete. This flag is automatically set if the CreateOptions flag FILE_NO_INTERMEDIATE _BUFFERING is set.
FILE_SEQUENTIAL_ONLY
All accesses to the file are sequential.
FILE_RANDOM_ACCESS
Accesses to the file can be random, so no sequential read-ahead operations should be performed on the file by FSDs or the system.
FILE_NO_INTERMEDIATE_BUFFERING
The file cannot be cached or buffered in a driver's internal buffers. This flag is incompatible with the DesiredAccess FILE_APPEND_DATA flag.
FILE_SYNCHRONOUS_IO_ALERT
All operations on the file are performed synchronously. Any wait on behalf of the caller is subject to premature termination from alerts. This flag also causes the I/O system to maintain the file position context. If this flag is set, the DesiredAccess SYNCHRONIZE flag also must be set.
FILE_SYNCHRONOUS_IO_NONALERT
All operations on the file are performed synchronously. Waits in the system to synchronize I/O queuing and completion are not subject to alerts. This flag also causes the I/O system to maintain the file position context. If this flag is set, the DesiredAccess SYNCHRONIZE flag also must be set.
FILE_CREATE_TREE_CONNECTION
Create a tree connection for this file in order to open it over the network. This flag is not used by device and intermediate drivers.
FILE_NO_EA_KNOWLEDGE
If the extended attributes on an existing file being opened indicate that the caller must understand EAs to properly interpret the file, fail this request because the caller does not understand how to deal with EAs. This flag is irrelevant for device and intermediate drivers.
FILE_OPEN_REPARSE_POINT
Open a file with a reparse point and bypass normal reparse point processing for the file. For more information, see the Remarks section.
FILE_DELETE_ON_CLOSE
Delete the file when the last handle to it is passed to NtClose. If this flag is set, the DELETE flag must be set in the DesiredAccess parameter.
FILE_OPEN_BY_FILE_ID
The file name that is specified by the ObjectAttributes parameter includes the 8-byte file reference number for the file. This number is assigned by and specific to the particular file system. If the file is a reparse point, the file name will also include the name of a device. Note that the FAT file system does not support this flag. This flag is not used by device and intermediate drivers.
FILE_OPEN_FOR_BACKUP_INTENT
The file is being opened for backup intent. Therefore, the system should check for certain access rights and grant the caller the appropriate access to the file before checking the DesiredAccess parameter against the file's security descriptor. This flag not used by device and intermediate drivers.
FILE_RESERVE_OPFILTER
This flag allows an application to request a filter opportunistic lock (oplock) to prevent other applications from getting share violations. If there are already open handles, the create request will fail with STATUS_OPLOCK_NOT_GRANTED. For more information, see the Remarks section.
FILE_OPEN_REQUIRING_OPLOCK
The file is being opened and an opportunistic lock (oplock) on the file is being requested as a single atomic operation. The file system checks for oplocks before it performs the create operation and will fail the create with a return code of STATUS_CANNOT_BREAK_OPLOCK if the result would be to break an existing oplock. For more information, see the Remarks section.Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP:  This flag is not supported.
This flag is supported on the following file systems: NTFS, FAT, and exFAT.

FILE_COMPLETE_IF_OPLOCKED
Complete this operation immediately with an alternate success code of STATUS_OPLOCK_BREAK_IN_PROGRESS if the target file is oplocked, rather than blocking the caller's thread. If the file is oplocked, another caller already has access to the file. This flag is not used by device and intermediate drivers.
*/