#pragma once

#include "IKernelObject.h"

class IWindowsKernelObject : public IKernelObject
{
public:
	IWindowsKernelObject() {};
public:
	const HANDLE GetHandle() { return m_handle; };

protected:
	HANDLE m_handle;
};