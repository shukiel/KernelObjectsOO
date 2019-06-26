#pragma once
#include <functional>
#include <windows.h>
#include <plog/Log.h>
#include "ObjectHandler/IKernelObject.h"
#include "ErrorHandling/Exceptions/SEExceptionHandler.h"
#include <ostream>

//Macro, not so good
/*

#define NTSTATUS_WRAPPER (STATUS) \
		\
		if (NT_INFORMATION (STATUS))\
		{\
			/ *LOG() TODO:: Add logger* /\
		}else if (NT_WARNING(STATUS))\
		{\
			/ *LOG EXCEPTION ?? TODO::* /\
		}\
		else if (!NT_SUCCESS(STATUS) && IsErrorFatal(rv, __FUNCTION__))\
		{\
			std::string::format(); \
			throw IException(""); \
		}else if(NT_ERROR(STATUS))\
		{ \
		}


Generic ::
template<typename Fn, Fn fn, typename... Args>
typename std::result_of<Fn(Args...)>::type NTWrapper(Args... args)
{
	std::result_of<Fn(Args...)>::type retyval =  fn(std::forward<Args>(args)...);
}

*/

std::ostream& operator<<(std::ostream& os, IO_STATUS_BLOCK* sb)
{
	os << L"IO_STATUS_BLOCK info=" << std::hex << sb->Information << L"Status (NTSTATUS=" << sb->Status << std::dec;
	return os;
}

#define NT_WRAPPER(FUNC) NTWrapper<decltype(&FUNC), &FUNC> 

template<typename Fn, Fn fn, typename... Args>
 NTSTATUS NTWrapper(IKernelObject* kernelObject, Args... args)
{
	plog::init(plog::info, "poop.log");

	NTSTATUS retval;
	try
	{
		retval = fn(std::forward<Args>(args)...);	
	}
	catch (...)
	{
		PLOGI << "Windows thrown an runtime error";
		std::cout << "Huge turd on my face" << std::endl;
	}

	if (NT_INFORMATION(retval))
	{
		/*LOG */ 
	}
	else if (NT_WARNING(retval))
	{
		/*LOG */ 
	}
	else if (NT_SUCCESS(retval))
	{
		PLOGI << "YAY";
	}
	else if (NT_ERROR(retval))
	{ 
		if (true)// kernelObject->IsErrorFatal(this->IsFatalError(retval,fn)))
		{
			std::stringstream ss;
			ss << L"Runtime error within" << __FUNCTION__;
			// ss << (args <<  ...) ;
			ss << "failed with code - 0x" << std::hex << retval << std::dec;
			std::cout << ss.str() << std::endl;
			PLOGI << ss.str();
			throw std::runtime_error(ss.str());
		}
		else
		{
			/*log warning, maybe throw a certain exception that would be handled in the calling func*/
		}
	}

}


#define HR_WRAPPER(FUNC) HRWrapper<decltype(&FUNC), &FUNC>

template<typename Fn, Fn fn, typename... Args>
 HRESULT HRWrapper(IKernelObject* kernelObject, Args... args)
{
	HRESULT retval = fn(std::forward<Args>(args)...);
	if (SUCCEEDED (retval))
	{
		//YAY!
	}
	else if (NT_ERROR(retval))
	{
		/*if (IsErrorFatal(rv,))
		throw ()*/
	}
}




//
//  HRESULTs are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +-+-+-+-+-+---------------------+-------------------------------+
//  |S|R|C|N|r|    Facility         |               Code            |
//  +-+-+-+-+-+---------------------+-------------------------------+
//
//  where
//
//      S - Severity - indicates success/fail
//
//          0 - Success
//          1 - Fail (COERROR)
//
//      R - reserved portion of the facility code, corresponds to NT's
//              second severity bit.
//
//      C - reserved portion of the facility code, corresponds to NT's
//              C field.
//
//      N - reserved portion of the facility code. Used to indicate a
//              mapped NT status value.
//
//      r - reserved portion of the facility code. Reserved for internal
//              use. Used to indicate HRESULT values that are not status
//              values, but are instead message ids for display strings.
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
