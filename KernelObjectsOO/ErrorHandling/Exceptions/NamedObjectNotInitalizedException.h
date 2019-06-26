#pragma once
#include "IException.h"

namespace OOException
{
														 
	class NamedObjectNotInitalizedException : public IException
	{
	public:
		NamedObjectNotInitalizedException() : IException(DWORD(-1), L"Tried to Create an object before initializing it!", IException::ErrCodeType::OO_ERROR_CODE) {};

		~NamedObjectNotInitalizedException()
		{
		}

		virtual const char* what() const override {return (CHAR*) m_errMessage.c_str();};
	protected:
	private:
	};
	
	
}//end OOException
