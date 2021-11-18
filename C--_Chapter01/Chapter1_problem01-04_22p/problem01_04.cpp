#include <iostream>

int main(void)
{
	int amount;
	double salary;
	
	while (1)
	{
		std::cout << "판매 금액을 만원 단위로 입력(-1 to end)";
		std::cin >> amount;

		if (amount == -1)
		{
			std::cout << "프로그램을 종료합니다." << std::endl;
			system("pause");
			return 0;
		}
		salary = 50 + amount * 0.12;

		std::cout << "이번 달 급여: " << salary << "만원" << std::endl;
	}
	
	system("pause");
	return 0;

	

	
}
