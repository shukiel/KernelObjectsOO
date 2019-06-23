#pragma once
#include <windows.h>
//#include <winnt.h>

class IShareAccess
{
public:
	enum class FileShareOptions 
	{
		Read = FILE_SHARE_READ, 
		Write = FILE_SHARE_WRITE,
		Delete = FILE_SHARE_DELETE
	};
	template <typename ...T>
	static DWORD CreateSharesMask(T ... args)
	{
		return ((DWORD)args | ... | 0);
	}
};