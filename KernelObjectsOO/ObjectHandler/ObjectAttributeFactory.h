#pragma once
#include "../targetver.h"
#include <windows.h>
#include <winternl.h>

namespace OOK
{
	class INamedObject; //Forward declaration
	
	
	class ObjectAttributeFactory
	{
	public:
		enum ObjectAttributeType { DEFAULT };
		static OBJECT_ATTRIBUTES CreateObjectAttribute(INamedObject* namedObject, ObjectAttributeType type);
	
	
	private:
		static OBJECT_ATTRIBUTES CreateDefaulObjectAttribute(INamedObject* namedObject);
	};
}