#include <iostream>

int main(void)
{
	int don;

	std::cout << "단을 입력해주세요 : ";
	std::cin >> don;

	for (int i = 1;i <= 9;i++)
	{
		std::cout << don << "*" << i << "=" << don * i << std::endl;
	}

	system("pause");
	return 0;
}