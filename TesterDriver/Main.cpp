#include "..\KernelObjectsOO\ObjectHandler\ConcreteObjects\file.h"
#include <iostream>



int main(int argc, char* argv[])
{
	File f; 
	f.INamedObject::Open(L"\\??\\C:\\kakja.txt");
}