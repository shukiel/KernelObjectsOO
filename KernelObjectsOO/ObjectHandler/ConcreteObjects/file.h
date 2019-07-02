#pragma once
#include "../INamedObject.h"
#include "FileOpenOptions.h"
#include "FileShareAccess.h"

namespace OOK
{
	class File : public INamedObject
	{
	public:
		virtual void Create() override;
	
	
		virtual void Close() override;
	
	
		virtual void Destroy() override;
	
	
		virtual void Open() override;

		using INamedObject::Open; //avoid shadowing
		
		virtual void Delete();
	
	
		std::wstring getUNCFileName();
	
	protected:
		FileOpenOptions m_openOptions;
		FileShareAccess m_shareOptions;
	private:
	};
}