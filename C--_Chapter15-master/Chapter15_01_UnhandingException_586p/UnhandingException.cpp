#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(void)
{
	int num1, num2;
	cout << "�� ���� ���� �Է�:";
	cin >> num1 >> num2;

	cout << "�������� ��: " << num1 / num2 << endl;
	cout << "�������� ������: " << num1 % num2 << endl;
	system("pause");
	return 0;
}