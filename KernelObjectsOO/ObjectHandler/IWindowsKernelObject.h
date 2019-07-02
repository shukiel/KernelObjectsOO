#pragma once

#include "IKernelObject.h"
#include <AccCtrl.h>
#include "IObjectAttributes.h"
#include <memory>

namespace OOK
{
	class IWindowsKernelObject : public IKernelObject
	{
	public:
		IWindowsKernelObject() {};
	
	public:
		const HANDLE& GetHandle() { return m_handle; };
		void setHandle(const HANDLE handle) { m_handle = handle; }

	protected:
		std::unique_ptr<IObjectAttribute> m_ObjectAttribute;

	private:
		HANDLE m_handle;
		SE_OBJECT_TYPE m_objectType;


	};
}