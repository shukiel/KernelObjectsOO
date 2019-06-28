#pragma once

#include "IKernelObject.h"
#include <AccCtrl.h>

namespace OOK
{
	class IWindowsKernelObject : public IKernelObject
	{
	public:
		IWindowsKernelObject() {};
	public:
		const HANDLE GetHandle() { return m_handle; };
	
	protected:
		HANDLE m_handle;
		SE_OBJECT_TYPE m_objectType;

	};
}