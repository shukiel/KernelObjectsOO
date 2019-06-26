#pragma once
#include <exception>
#include <windows.h>

//Catch SEH exception as C++ exception 
namespace OOException
{
	
	class SE_Exception : public std::exception
	{
	private:
		unsigned int m_exceptionCode;
	public:
		SE_Exception() : m_exceptionCode{ 0 } {}
		SE_Exception(unsigned int n) : m_exceptionCode{ n } {}
		unsigned int getExceptionCode() { return m_exceptionCode; }
	};
	
	void TranslateFunction(unsigned int code, PEXCEPTION_POINTERS)
	{
		throw SE_Exception(code);
	}
	
	
	static auto OriginalFunc = _set_se_translator(&TranslateFunction);
}//end OOException