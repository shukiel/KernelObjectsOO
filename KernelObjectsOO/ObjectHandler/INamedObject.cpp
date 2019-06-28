#include "pch.h"
#include "INamedObject.h"
#include "../ErrorHandling/Exceptions/NamedObjectNotInitalizedException.h"

namespace OOK
{
	
	void INamedObject::Open()
	{
		if (!m_isNameInitialized) 
			throw new OOException::NamedObjectNotInitalizedException();
	}
	
	void INamedObject::Open(std::wstring objectName)
	{
		m_name = objectName;
		m_isNameInitialized = true; 
		Open();
	}

}
