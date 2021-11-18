#include <iostream>
#include <cstring>
#include "NameCard.h"

using std::cout;
using std::endl;

void COM_POS::ShowPositionInfo(int pos)
{
	switch (pos)
	{
	case CLERK:
		cout << "사원" << endl;
		break;
	case SENIOR:
		cout << "주임" << endl;
		break;
	case ASSIST:
		cout << "대리" << endl;
		break;
	case MANAGER:
		cout << "과장" << endl;
		break;
	}
}


NameCard::NameCard(const char * _name, const char * _company, const char * _phone, int pos) :position(pos)
{
	int len = strlen(_name) + 1;
	name = new char[len];
	strcpy_s(name, len, _name);
	len = strlen(_company) + 1;
	company = new char[len];
	strcpy_s(company, len, _company);

	len = strlen(_phone) + 1;
	phone = new char[len];
	strcpy_s(phone, len, _phone);

}

NameCard::NameCard(const NameCard &copy) :position(copy.position)
{
	int len = strlen(copy.name) + 1;
	name = new char[len];
	strcpy_s(name, len, copy.name);

	len = strlen(copy.company) + 1;
	company = new char[len];
	strcpy_s(company, len, copy.company);

	len = strlen(copy.phone) + 1;
	phone = new char[len];
	strcpy_s(phone, len, copy.phone);
}

void NameCard::ShowNameCardInfo() const
{
	cout << "이름: " << name << endl;
	cout << "회사: " << company << endl;
	cout << "전화번호: " << phone << endl;
	cout << "직급: "; COM_POS::ShowPositionInfo(position);
	cout << endl;
}

NameCard::~NameCard()
{
	delete[]name;
	delete[]company;
	delete[]phone;
	cout << "called destructor" << endl;
}

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COM_POS::CLERK);
	NameCard copy1 = manClerk;

	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COM_POS::SENIOR);
	NameCard copy2 = manSenior;

	
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	system("pause");
	return 0;
}