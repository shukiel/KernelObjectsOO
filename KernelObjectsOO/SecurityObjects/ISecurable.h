#pragma once
#include <winnt.h>

class ISecurable 
{
public:
protected:
	SID m_ownerSID;
	SID m_groupSID;
	ACL m_DACL;
	ACL m_systemACL;
private:
	SECURITY_DESCRIPTOR m_nativeSecurityDescriptor = {};
};
