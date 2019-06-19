#include "IKernelObject.h"

class IWindowsKernelObject : public IKernelObject 
{
    public:
    const HANDLE GetHandle() { return m_handle };
    
    private:
    const HANDLE m_handle;
}