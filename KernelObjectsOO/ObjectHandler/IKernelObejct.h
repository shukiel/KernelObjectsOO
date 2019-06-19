// Enosh Cohen
// TODO: Add includes

class IKernelObject
{
    public:
    void Create()=0;
    void Close()=0;         //Will close the refference of the HANDLE
    void Destroy()=0;       //Will delete the associated HANDLE

    private:
    DWORD m_pid;
    bool m_currentProcessOwner;
}