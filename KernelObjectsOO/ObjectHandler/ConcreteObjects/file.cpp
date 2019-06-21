#include "file.h"
#include <winternl.h>
#include <stdexcept>
#include "../IShareAccess.h"
#include "../ObjectAttributeFactory.h"


void File::Create()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void File::Close()
{
	throw std::logic_error("The method or operation is not implemented.");
}

void File::Destroy()
{
	NtClose(this->m_handle);
}

void File::Open()
{
	__super::Open();

	IO_STATUS_BLOCK statusBlock;
	HANDLE outHandle;
	NtOpenFile(
		&outHandle,
		IShareAccess::CreateSharesMask(IShareAccess::Read, IShareAccess::Write, IShareAccess::Delete),
		&ObjectAttributeFactory::CreateObjectAttribute(this, ObjectAttributeFactory::ObjectAttributeType::DEFAULT),
		&statusBlock,
		IShareAccess::CreateSharesMask(IShareAccess::Read, IShareAccess::Write, IShareAccess::Delete), 
		FileOpenOptions::CreateFileOpenOptionsMask());
}
