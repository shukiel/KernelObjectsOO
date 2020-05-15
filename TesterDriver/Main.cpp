#include "..\KernelObjectsOO\ObjectHandler\ConcreteObjects\file.h"
#include "../KernelObjectsOO/init.h"
#include <iostream>



int main(int argc, char* argv[])
{
	INIT_OOK;
	OOK::File f;
	f.INamedObject::Open((L"\\??\\C:\\kaka.txt"));
	f.Open();
	return 0;
}
