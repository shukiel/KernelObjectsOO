#include "..\KernelObjectsOO\ObjectHandler\ConcreteObjects\file.h"


int main(int argc, char* argv[])
{
	File x;
	x.INamedObject::Open(L"\\??\\C:\\kaka.txt");
	x.Close();
	return 0;
}