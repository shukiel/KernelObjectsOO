#pragma once
#include <windows.h>
// #include <winnt.h>
// #include <WinInet.h>

//This abstract class will supply us with the standard, Basic and Generic Access Rights options, for object specific access - look for the specific sub-classes.
class IAccessRights
{
public:
	//Using these will turn on the correct bits within the specific access rights, depending on the object type
	enum class GenericAccessRights 
	{
		Read = GENERIC_READ,
		Write = GENERIC_WRITE,
		Execute = GENERIC_EXECUTE,
		All = GENERIC_ALL
	}; 

	enum class StandartAccessRights
	{
		Read = STANDARD_RIGHTS_READ,
		Write = STANDARD_RIGHTS_WRITE,
		Execute = STANDARD_RIGHTS_EXECUTE,
		All = STANDARD_RIGHTS_ALL
	};			 

	enum class BasicAccessRight 
	{
		Delete = DELETE,
		ReadControl = READ_CONTROL,
		WriteDAC = WRITE_DAC,
		WriteOwner = WRITE_OWNER,
		Syncronize = SYNCHRONIZE
	};

	//Specific Rights
	static const ACCESS_MASK AllSpecificRights = SPECIFIC_RIGHTS_ALL;

	//System Access 
	static const ACCESS_MASK SyetmSecurity = ACCESS_SYSTEM_SECURITY;

	//Maximum Access
	static const ACCESS_MASK Maximum = MAXIMUM_ALLOWED;
	
};

//    1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//   +-------+-------+---------------+-------------------------------+
//   |Generic|Special| StandardRights|         SpecificRights        |
//   |Rights |Rights |   Rights      |                               |
//   +-------+-------+---------------+-------------------------------+



/*
#define DELETE                           (0x00010000L)
#define READ_CONTROL                     (0x00020000L)
#define WRITE_DAC                        (0x00040000L)
#define WRITE_OWNER                      (0x00080000L)
#define SYNCHRONIZE                      (0x00100000L)

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define STANDARD_RIGHTS_READ             (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE            (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE          (READ_CONTROL)

#define STANDARD_RIGHTS_ALL              (0x001F0000L)

#define SPECIFIC_RIGHTS_ALL              (0x0000FFFFL)


// begin_wdm
//
//  The following are masks for the predefined standard access types
//

#define DELETE                           (0x00010000L)
#define READ_CONTROL                     (0x00020000L)
#define WRITE_DAC                        (0x00040000L)
#define WRITE_OWNER                      (0x00080000L)
#define SYNCHRONIZE                      (0x00100000L)

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define STANDARD_RIGHTS_READ             (READ_CONTROL)
#define STANDARD_RIGHTS_WRITE            (READ_CONTROL)
#define STANDARD_RIGHTS_EXECUTE          (READ_CONTROL)

#define STANDARD_RIGHTS_ALL              (0x001F0000L)

#define SPECIFIC_RIGHTS_ALL              (0x0000FFFFL)

//
// AccessSystemAcl access type
//

#define ACCESS_SYSTEM_SECURITY           (0x01000000L)

//
// MaximumAllowed access type
//

#define MAXIMUM_ALLOWED                  (0x02000000L)

//
//  These are the generic rights.
//

#define GENERIC_READ                     (0x80000000L)
#define GENERIC_WRITE                    (0x40000000L)
#define GENERIC_EXECUTE                  (0x20000000L)
#define GENERIC_ALL                      (0x10000000L)

//
//  Define the generic mapping array.  This is used to denote the
//  mapping of each generic access right to a specific access mask.
//
*/