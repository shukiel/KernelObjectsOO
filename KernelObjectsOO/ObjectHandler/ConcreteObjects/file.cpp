#include "file.h"
#include<windows.h>
#include <winternl.h>
#include <stdexcept>
#include "../IShareAccess.h"
#include "../ObjectAttributeFactory.h"
#include "FileOpenOptions.h"
#include "../IAccessOptions.h"
#include <iostream>


void File::Create()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void File::Close()
{
	NtClose(this->m_handle);
}

void File::Destroy()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void File::Open()
{
	__super::Open();

	IO_STATUS_BLOCK statusBlock;
	HANDLE outHandle;
	NTSTATUS rv = NtOpenFile(
		&outHandle,
		(ACCESS_MASK)IAccessRights::GenericAccessRights::All,
		&ObjectAttributeFactory::CreateObjectAttribute(this, ObjectAttributeFactory::ObjectAttributeType::DEFAULT),
		&statusBlock,
		IShareAccess::CreateSharesMask(IShareAccess::FileShareOptions::Read, IShareAccess::FileShareOptions::Write, IShareAccess::FileShareOptions::Delete),
		(ULONG)FileOpenOptions::FileType::NonDirectoryFile);
	std::cout << rv << std::endl;
}

void File::Delete()
{
	throw std::logic_error("The method or operation is not implemented.");
	
}

std::wstring File::getUNCFileName()
{
	throw std::logic_error("Not implemented");
}
