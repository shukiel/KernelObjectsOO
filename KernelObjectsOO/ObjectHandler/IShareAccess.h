#pragma once
#include <winnt.h>

class IShareAccess
{
public:
	static enum FileShareOptions 
	{
		Read = FILE_SHARE_READ, 
		Write = FILE_SHARE_WRITE,
		Delete = FILE_SHARE_DELETE
	};

	template<FileShareOptions...>
	static DWORD CreateSharesMask(FileShareOptions args...)
	{
		return (args | ... | 0);
	}
};