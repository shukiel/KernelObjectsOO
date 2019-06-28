#pragma once

namespace tools
{
	template<typename ...ToCheck>
	static constexpr bool isTypeRight(ToCheck ... type);
}