#pragma once

#define NTSTATUS_WRAPPER (STATUS) \
		\
		if (NT_INFORMATION (STATUS))\
		{\
			/*LOG() TODO:: Add logger*/\
		}else if (NT_WARNING(STATUS))\
		{\
			/*LOG EXCEPTION ?? TODO::*/\
		}\
		else if (!NT_SUCCESS(STATUS) && IsErrorFatal(rv, __FUNCTION__))\
		{\
			std::string::format(); \
			throw IException(""); \
		}else if(NT_ERROR(STATUS))\
		{ \
		}


