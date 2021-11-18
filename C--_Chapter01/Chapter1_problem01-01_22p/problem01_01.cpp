#include <iostream>

int main(void)
{
	int sum = 0;
	int val1;
	for (int i = 1;i <= 5;i++)
	{
		std::cout << i << "번째 정수 입력: ";
		std::cin >> val1;
		sum = sum + val1;
	}

	std::cout << "합계: " << sum << std::endl;

	system("pause");
	return 0;
}