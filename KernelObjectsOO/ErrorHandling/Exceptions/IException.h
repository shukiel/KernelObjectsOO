#pragma once
#include <exception>
#include <windows.h>
#include <string>
namespace OOException
{
	class IException : public std::exception 
	{
	public:
		enum class ErrCodeType {NTSTATUS, HRESULT, OO_ERROR_CODE};

		IException() = default;
		
		IException(DWORD errCode, const std::wstring& errMessage, ErrCodeType errCodeType) : m_errCode(errCode), m_errMessage(errMessage), m_errCodeType(errCodeType) {}
		virtual const char* what() const = 0 ;

	protected:

		DWORD m_errCode = 0;
		std::wstring m_errMessage = L"";
		ErrCodeType m_errCodeType = ErrCodeType::OO_ERROR_CODE;
	};
}//end OOException