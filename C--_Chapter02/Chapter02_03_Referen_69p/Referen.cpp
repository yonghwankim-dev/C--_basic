#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int num1 = 10;
	int &num2 = num1;

	num2 = 3047;

	cout << num1 << endl;
	cout << num2 << endl;
	cout << &num1 << endl;
	cout << &num2 << endl;

	system("pause");

	return 0;
}