//#include "targetver.h"
#include "StringTools.h"


namespace tools
{
	PUNICODE_STRING getUnicodeStringFromWstring(std::wstring in)
	{
		PUNICODE_STRING out = new UNICODE_STRING;
		RtlInitUnicodeString(out, in.c_str());
		//TODO Memory leak?!
		return out;
	}
}
