#include "pch.h"
#include "file.h"
#include <stdexcept>
#include "../IShareAccess.h"
#include "../ObjectAttributeFactory.h"
#include "FileOpenOptions.h"
#include "../IAccessOptions.h"
#include "ErrorHandling/NT_Wrapper.h"



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

	NT_WRAPPER(NtOpenFile)(this,
		&outHandle,
		(ACCESS_MASK)IAccessRights::GenericAccessRights::All,
		&ObjectAttributeFactory::CreateObjectAttribute(this, ObjectAttributeFactory::ObjectAttributeType::DEFAULT),
		&statusBlock,
		IShareAccess::CreateSharesMask(IShareAccess::FileShareOptions::Read, IShareAccess::FileShareOptions::Write, IShareAccess::FileShareOptions::Delete),
		(ULONG)FileOpenOptions::FileType::NonDirectoryFile);
	m_handle = outHandle;
}

void File::Delete()
{
}

std::wstring File::getUNCFileName()
{
	throw std::logic_error("Not implemented");
}
