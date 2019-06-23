#pragma once	
#include <windows.h>
#include <winternl.h>
#include <string>

namespace tools
{
	PUNICODE_STRING getUnicodeStringFromWstring(std::wstring in);
}