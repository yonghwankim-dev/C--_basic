#include <iostream>

int main(void)
{
	char name[100];
	char tel[100];
	
	std::cout << "�̸��� �Է����ּ��� : ";
	std::cin >> name;

	std::cout << "��ȭ��ȣ�� �Է����ּ��� : ";
	std::cin >> tel;

	std::cout << "�̸� : " << name<<std::endl;
	std::cout << "��ȭ��ȣ : " << tel<<std::endl;

	system("pause");
	return 0;
}