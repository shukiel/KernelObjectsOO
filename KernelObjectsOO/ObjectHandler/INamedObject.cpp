#include "INamedObject.h"
#include "../ErrorHandling/Exceptions/NamedObjectNotInitalizedException.h"


void INamedObject::Open()
{
	if (!m_isNameInitialized) 
		throw new NamedObjectNotInitalizedException();
}
