#include <iostream>

using std::cout;
using std::endl;

void Divide(int num1, int num2)
{
	try {
		if (num2 == 0)
			throw 0;
		cout << "��: " << num1 / num2 << endl;
		cout << "������: " << num1 % num2 << endl;
	}
	catch (int expn)
	{
		cout << "First Catch" << endl;
		throw;	// �ٽ� ������.
	}
}

int main(void)
{
	try {
		Divide(9, 2);
		Divide(4, 0);
	}
	catch (int expn)
	{
		cout << "second catch" << endl;
	}

	system("pause");
	return 0;
}