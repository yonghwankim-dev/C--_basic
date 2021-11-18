#include <iostream>
#include <cstring>
#include "Printer.h"
using std::cout;
using std::endl;

void Printer::SetString(const char * str)
{
	strcpy_s(ch, PRINTER_ENUM::STR_LEN, str);
	return;
}

void Printer::ShowString()
{
	cout << ch << endl;
	return;
}