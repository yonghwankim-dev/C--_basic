#include <iostream>
#include "Printer.h"

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	
	system("pause");
	return 0;
}
