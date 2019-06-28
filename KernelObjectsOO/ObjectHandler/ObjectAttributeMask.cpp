#include "pch.h"
#include "ObjectAttributeMask.h"

namespace OOK
{
	LONG ObjectAttributeMask::getNativeAttributeMask()
	{
		LONG res = 0;
		res |= m_isInheritable				? OBJ_INHERIT 			   :0;
		res |= m_isClosedOnZeroRefference	? OBJ_PERMANENT			   :0;
		res |= m_exclusive					? OBJ_EXCLUSIVE			   :0;
		res |= m_caseSensitive				? OBJ_CASE_INSENSITIVE	   :0;
		res |= m_openIfExists				? OBJ_OPENIF			   :0;
		res |= m_openLinkNotTarget			? OBJ_OPENLINK			   :0;
		res |= m_kernelHandle				? OBJ_KERNEL_HANDLE		   :0;
		res |= m_checkAccessInKernelMode	? OBJ_FORCE_ACCESS_CHECK   :0;
	}
}
