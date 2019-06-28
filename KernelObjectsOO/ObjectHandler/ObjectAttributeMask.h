#pragma once
#include <windows.h>

//See ref @ https://docs.microsoft.com/en-us/windows/desktop/api/ntdef/ns-ntdef-_object_attributes


namespace OOK
{
	class ObjectAttributeMask 
	{
	public:
		ObjectAttributeMask(
			bool isInheritable,
			bool isClosedOnZeroRefference,
			bool exclusive,
			bool caseSensitive,
			bool openIfExists,
			bool openLinkNotTarget,
			bool kernelHandle,
			bool checkAccessInKernelMode) :
			m_isInheritable(isInheritable),
			m_isClosedOnZeroRefference(isClosedOnZeroRefference),
			m_exclusive(exclusive),
			m_caseSensitive(caseSensitive),
			m_openIfExists(openIfExists),
			m_openLinkNotTarget(openLinkNotTarget),
			m_kernelHandle(kernelHandle),
			m_checkAccessInKernelMode(checkAccessInKernelMode) {}
	
		operator LONG() { return getNativeAttributeMask(); }
	
	protected:
	
	private:
		bool m_isInheritable;				//OBJ_INHERIT;
		bool m_isClosedOnZeroRefference;	//OBJ_PERMANENT
		bool m_exclusive;					//OBJ_EXCLUSIVE
		bool m_caseSensitive;				//OBJ_CASE_INSENSITIVE
		bool m_openIfExists;				//OBJ_OPENIF
		bool m_openLinkNotTarget;			//OBJ_OPENLINK
		bool m_kernelHandle;				//OBJ_KERNEL_HANDLE
		bool m_checkAccessInKernelMode;		//OBJ_FORCE_ACCESS_CHECK
	
		/*	Currently not documented.
		bool m_	OBJ_IGNORE_IMPERSONATED_DEVICEMAP
		bool m_	OBJ_DONT_REPARSE
		bool m_	OBJ_VALID_ATTRIBUTES
		*/
	
		LONG getNativeAttributeMask();
	};
}