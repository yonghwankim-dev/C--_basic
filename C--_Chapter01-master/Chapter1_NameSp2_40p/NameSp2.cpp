#include <iostream>

namespace BestComImp1
{
	void SimpleFunc(void);

}

namespace ProgComImp1
{
	void SimpleFunc(void);
}

int main(void)
{
	BestComImp1::SimpleFunc();
	ProgComImp1::SimpleFunc();

	system("pause");
	return 0;
}


void BestComImp1::SimpleFunc(void)
{
	std::cout << "BestCom�� ������ �Լ�" << std::endl;
}

void ProgComImp1::SimpleFunc(void)
{
	std::cout << "ProgCom�� ������ �Լ�" << std::endl;
}