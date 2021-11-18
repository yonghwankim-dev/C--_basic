#include <iostream>
#include "Calculator.h"
using std::cout;
using std::endl;

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.2, 2.4) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(3.2, 2.4) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(3.2, 2.4) << endl;
	cal.ShowOpCount();

	system("pause");
	return 0;
}

