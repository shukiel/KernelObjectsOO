#pragma once
#include <winternl.h>

class INamedObject; //Forward declaration


class ObjectAttributeFactory
{
public:
	enum ObjectAttributeType { DEFAULT };
	static OBJECT_ATTRIBUTES CreateObjectAttribute(INamedObject* namedObject, ObjectAttributeType type);


private:
	static OBJECT_ATTRIBUTES CreateDefaulObjectAttribute(INamedObject* namedObject);
};