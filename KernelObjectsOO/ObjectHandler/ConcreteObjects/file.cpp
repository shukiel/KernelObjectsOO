#include "pch.h"
#include "file.h"
#include <stdexcept>
#include "../ObjectAttributeFactory.h"
#include "FileOpenOptions.h"
#include "../IAccessOptions.h"
#include "ErrorHandling/NT_Wrapper.h"
#include "FileShareAccess.h"


namespace OOK
{
	void File::Create()
	{
		throw std::logic_error("The method or operation is not implemented.");
	}
	
	void File::Close()
	{
		NT_WRAPPER(NtClose)(this->GetHandle());
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
	
		NT_WRAPPER(NtOpenFile)(
			&outHandle,
			(ACCESS_MASK)IAccessRights::GenericAccessRights::All,
			&ObjectAttributeFactory::CreateObjectAttribute(this, ObjectAttributeFactory::ObjectAttributeType::DEFAULT),
			&statusBlock,
			FileShareAccess::CreateSharesMask(FileShareAccess::FileShareOptions::Read, FileShareAccess::FileShareOptions::Write, FileShareAccess::FileShareOptions::Delete),
			(ULONG)FileOpenOptions::FileType::NonDirectoryFile);

		setHandle(outHandle);
	}
	
	void File::Delete()
	{
	}
	
	std::wstring File::getUNCFileName()
	{
		throw std::logic_error("Not implemented");
	}
}
