#include <windows.h>

namespace tools
{
	template<typename ...ToCheck>
	static constexpr bool isTypeRight(const ToCheck ... type)
	{	
		//TODO:: Add type safe check for variadic template
		return true;
	}
}
