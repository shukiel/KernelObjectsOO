#include "pch.h"
#include "ObjectAttributeFactory.h"
#include "INamedObject.h"
#include "Tools/StringTools.h"

OBJECT_ATTRIBUTES ObjectAttributeFactory::CreateObjectAttribute(INamedObject *namedObject, ObjectAttributeType type)
{
	switch(type)
	{
	case DEFAULT:
		return CreateDefaulObjectAttribute(namedObject);
	}

	return OBJECT_ATTRIBUTES();
}

OBJECT_ATTRIBUTES ObjectAttributeFactory::CreateDefaulObjectAttribute(INamedObject* namedObject)
{
	OBJECT_ATTRIBUTES outObjectAttribute;
	PUNICODE_STRING tempName = tools::getUnicodeStringFromWstring(namedObject->getName());
	InitializeObjectAttributes(&outObjectAttribute, tempName,OBJ_INHERIT, NULL, NULL);
	return outObjectAttribute;
}



/*
OBJ_INHERIT
This handle can be inherited by child processes of the current process.

OBJ_PERMANENT
This flag only applies to objects that are named within the object manager. By default, such objects are deleted when all open handles to them are closed. If this flag is specified, the object is not deleted when all open handles are closed. Drivers can use ZwMakeTemporaryObject to delete permanent objects.

OBJ_EXCLUSIVE
Only a single handle can be open for this object.

OBJ_CASE_INSENSITIVE
If this flag is specified, a case-insensitive comparison is used when matching the ObjectName parameter against the names of existing objects. Otherwise, object names are compared using the default system settings.

OBJ_OPENIF
If this flag is specified to a routine that creates objects, and that object already exists then the routine should open that object. Otherwise, the routine creating the object returns an NTSTATUS code of STATUS_OBJECT_NAME_COLLISION.

OBJ_KERNEL_HANDLE
Specifies that the handle can only be accessed in kernel mode.

OBJ_FORCE_ACCESS_CHECK


in nactual header
#define OBJ_INHERIT                         0x00000002L
#define OBJ_PERMANENT                       0x00000010L
#define OBJ_EXCLUSIVE                       0x00000020L
#define OBJ_CASE_INSENSITIVE                0x00000040L
#define OBJ_OPENIF                          0x00000080L
#define OBJ_OPENLINK                        0x00000100L
#define OBJ_KERNEL_HANDLE                   0x00000200L
#define OBJ_FORCE_ACCESS_CHECK              0x00000400L
#define OBJ_IGNORE_IMPERSONATED_DEVICEMAP   0x00000800L
#define OBJ_DONT_REPARSE                    0x00001000L
#define OBJ_VALID_ATTRIBUTES                0x00001FF2L

*/