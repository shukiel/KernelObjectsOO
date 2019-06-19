#include "IWindowsKernelObject.h"

//TODO: Add includes

class INamedObject : public IKernelObjects
{
    public:
    std::wstring(getName);

    private:
    std::wstring m_name; //immutable
}