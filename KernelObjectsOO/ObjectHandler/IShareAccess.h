#pragma once
#include <windows.h>
#include "../Tools/TypeSafe.h"

namespace OOK
{
	class IShareAccess
	{
	public:
		template <typename ...T>
		static DWORD CreateSharesMask(const T ... args)
		{
			//TODO:: Check typeSafe
			return ((DWORD)args | ... | 0);
		}
	};
}