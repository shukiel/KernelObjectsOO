#pragma once
#include "../IShareAccess.h"

namespace OOK
{
	class FileShareAccess : public IShareAccess
	{
	public:
		enum class FileShareOptions
		{
			Read = FILE_SHARE_READ,
			Write = FILE_SHARE_WRITE,
			Delete = FILE_SHARE_DELETE
		};

	};
}