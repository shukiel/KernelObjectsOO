#include "pch.h"
#include "IObjectAttributes.h"
#include "Tools\StringTools.h"

namespace OOK
{
	OBJECT_ATTRIBUTES& IObjectAttribute::getNativeObject_Attributtes()
	{
		PUNICODE_STRING ucString = tools::getUnicodeStringFromWstring(m_ObjectName);
		ULONG attMask = m_objectAttributeMask;

		InitializeObjectAttributes(
			&m_nativeObjectAttribute,
			ucString,
			attMask,
			m_rootDirectory,
			&m_securityDescriptor
		);
	}
}
