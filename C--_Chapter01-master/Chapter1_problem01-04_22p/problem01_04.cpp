#include <iostream>

int main(void)
{
	int amount;
	double salary;
	
	while (1)
	{
		std::cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end)";
		std::cin >> amount;

		if (amount == -1)
		{
			std::cout << "���α׷��� �����մϴ�." << std::endl;
			system("pause");
			return 0;
		}
		salary = 50 + amount * 0.12;

		std::cout << "�̹� �� �޿�: " << salary << "����" << std::endl;
	}
	
	system("pause");
	return 0;

	

	
}
