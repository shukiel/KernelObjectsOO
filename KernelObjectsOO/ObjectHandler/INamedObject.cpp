#include "INamedObject.h"
#include "../ErrorHandling/Exceptions/NamedObjectNotInitalizedException.h"


void INamedObject::Open()
{
	if (!m_isNameInitialized) 
		throw new NamedObjectNotInitalizedException();
}

void INamedObject::Open(std::wstring objectName)
{
	m_name = objectName; m_isNameInitialized = true; Open();
}
