#include <iostream>

using std::cout;
using std::endl;
using std::cin;

void Divide(int num1, int num2)
{
	if (num2 == 0)
	{
		throw num2;
	}
	cout << "������ ��:" << num1 / num2 << endl;
	cout << "�������� ������:" << num1 % num2 << endl;
}


int main(void)
{
	int num1, num2;
	cout << "�� ���� ���� �Է�";
	cin >> num1 >> num2;

	try {
		Divide(num1, num2);
		cout << "�������� ���ƽ��ϴ�." << endl;
	}
	catch (int expn)
	{
		cout << "������ " << expn << "�� �� �� �����ϴ�." << endl;
		cout << "���α׷��� �ٽ� �����ϼ���." << endl;
	}
	cout << "end of main" << endl;
	system("pause");
	return 0;
}