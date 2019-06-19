// Enosh Cohen
// TODO: Add includes
#include <Windows.h>

class IKernelObject
{
public:
	virtual void Create() = 0;			//KAKA
	virtual void Close() = 0;			//Will close the reference of the HANDLE
	virtual void Destroy() = 0;			//Will delete the associated HANDLE

private:
	DWORD m_pid;
	bool m_currentProcessOwner;
};