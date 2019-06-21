#pragma once

#include "IKernelObject.h"

class IWindowsKernelObject : public IKernelObject
{
public:
	const HANDLE GetHandle() { return m_handle; };

protected:
	const HANDLE m_handle;
};