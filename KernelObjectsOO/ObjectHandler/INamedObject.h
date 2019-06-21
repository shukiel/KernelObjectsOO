#pragma once

#include "IWindowsKernelObject.h"
#include <string>
//TODO: Add includes

class INamedObject : public IWindowsKernelObject
{
public:
	virtual void openByName(std::wstring objectName) { m_name = objectName; m_isNameInitialized = true; Open(); };
	virtual void Open() override ;
	std::wstring getName() { return m_name; };

protected:
	std::wstring m_name = L""; //immutable
	bool m_isNameInitialized = false;
};