#pragma once
#include "../INamedObject.h"

class File : public INamedObject
{

public:
	virtual void Create() override;


	virtual void Close() override;


	virtual void Destroy() override;


	virtual void Open() override;


	std::wstring getUNCFileName();
};