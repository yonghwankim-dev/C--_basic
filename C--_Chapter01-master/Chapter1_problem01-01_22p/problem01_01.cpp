#include <iostream>

int main(void)
{
	int sum = 0;
	int val1;
	for (int i = 1;i <= 5;i++)
	{
		std::cout << i << "��° ���� �Է�: ";
		std::cin >> val1;
		sum = sum + val1;
	}

	std::cout << "�հ�: " << sum << std::endl;

	system("pause");
	return 0;
}