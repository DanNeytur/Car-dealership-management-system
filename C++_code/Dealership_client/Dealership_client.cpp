#include <iostream>
#include <string>
#include "Dealership_system.h"
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new (_NORMAL_BLOCK ,__FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

using namespace std;

int main()
{

	Dealership_system D;
	D.start();
	D.~Dealership_system();

	cout << "Leaks: " << _CrtDumpMemoryLeaks() << endl;

	return 0;
}

