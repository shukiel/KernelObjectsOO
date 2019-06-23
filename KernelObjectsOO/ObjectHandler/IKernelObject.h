#pragma once

// Enosh Cohen
// TODO: Add includes
#include <Windows.h>
#include "../targetver.h"


class IKernelObject
{
public:
	IKernelObject() {};
public:
	virtual void Create() = 0;			//Create an Object -- Might be obsolete using factories
	virtual void Open() = 0;
	virtual void Close() = 0;			//Will close the reference of the HANDLE
	virtual void Destroy() = 0;			//Will delete the associated HANDLE

protected:
	DWORD m_pid;
	bool m_currentProcessOwner;
};