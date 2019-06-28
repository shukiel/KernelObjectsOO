#pragma once

#include "IWindowsKernelObject.h"
#include <string>
//TODO: Add includes

namespace OOK
{
	class INamedObject : public IWindowsKernelObject
	{
	public:
		INamedObject() : m_name(L""), m_isNameInitialized(false) {};
	public:
		virtual void Open(std::wstring objectName);	//Opening a named object by name
		
		virtual void Open() override ;
		std::wstring getName() { return m_name; };
	
	protected:
		std::wstring m_name; //immutable
		bool m_isNameInitialized;
	};
}