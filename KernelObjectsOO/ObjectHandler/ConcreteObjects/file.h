#pragma once
#include "../INamedObject.h"

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
	};
}