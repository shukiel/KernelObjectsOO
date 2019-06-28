#include "..\KernelObjectsOO\ObjectHandler\ConcreteObjects\file.h"
#include <iostream>



int main(int argc, char* argv[])
{
	OOK::File f;
	f.INamedObject::Open((L"\\??\\C:\\kaka.txt"));
	f.Open();
}