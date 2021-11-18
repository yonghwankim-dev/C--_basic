#include "BankingSystemVer04.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using admin::account_create;
using admin::deposit;
using admin::withdraw;
using admin::all_seek;
using admin::show_menu;

cus * c[100];
int index = 0;					// 계좌생성 인덱스
int id;							// 입출금시 계좌ID 입력변수
int sum;						// 입출금액 입력변수
char namestr[100];

// 계좌생성
void admin::account_create(void)
{
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이 름: ";
	cin >> namestr;
	cout << "입금액: ";
	cin >> sum;

	if (sum < 0 || id<0)
	{
		return;
	}

	c[index] = new cus(id, namestr, sum);

	index++;
}

// 입금
void admin::deposit()
{
	cout << "[입	금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}

	for (int i = 0;i < index;i++)
	{
		if (c[i]->Get_accNum() == id)
		{
			c[i]->Set_Plus_balance(sum);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}

// 출금
void admin::withdraw()
{
	cout << "[출	금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}

	for (int i = 0;i < index;i++)
	{
		if (c[i]->Get_accNum() == id)
		{
			c[i]->Set_Minus_balance(sum);
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}
// 전체고객 잔액조회
void admin::all_seek(void)
{
	for (int i = 0;i < index;i++)
	{
		cout << "계좌ID: " << c[i]->Get_accNum() << endl;
		cout << "이름: " << c[i]->Get_Name() << endl;
		cout << "잔액: " << c[i]->Get_balance() << endl << endl;
	}
}

// 메뉴
void admin::show_menu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

// 고객 객체 생성자
cus::cus(int myAccNum, const char * myname, int mybalance) :accNum(myAccNum), balance(mybalance)
{
	int len = strlen(myname) + 1;
	name = new char[len];
	strcpy_s(name, len, myname);
}

// 고객 객체 복사생성자
cus::cus(const cus &ref) : accNum(ref.accNum), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
}

// 계좌ID 반환
int cus::Get_accNum() const
{
	return cus::accNum;
}

// 입금
void cus::Set_Plus_balance(int sum)
{
	if (sum < 0)
	{
		cout << "0보다 큰 수를 입력해주세요" << endl;
		return;
	}
	cus::balance += sum;
}

// 인출
void cus::Set_Minus_balance(int sum)
{
	if (cus::balance - sum < 0)
	{
		cout << "잔액이 부족합니다." << endl;
		return;
	}
	cus::balance -= sum;
}

// 이름 반환
char* cus::Get_Name() const
{
	return cus::name;
}

// 잔액 반환
int cus::Get_balance() const
{
	if (cus::balance < 0)
	{
		cout << "통장 잔액이 없습니다." << endl;
		return 0;
	}

	return cus::balance;
}

// 소멸자
cus::~cus()
{
	delete[]cus::name;
	cout << "called destructor" << endl;
}

int main(void)
{
	int number;
	while (1)
	{
		show_menu();

		cin >> number;

		if (number == function::MAKE)
		{
			account_create();
		}
		else if (number == function::DEPOSIT)
		{
			deposit();
		}
		else if (number == function::WITHDRAW)
		{
			withdraw();
		}
		else if (number == function::INQUIRE)
		{
			all_seek();
		}
		else if (number == function::EXIT)
		{
			for (int i = 0;i < index;i++)
			{
				delete c[i];
				cout << "called destructor" << endl;
			}
			cout << "프로그램 종료" << endl;
			break;
		}
		else {
			continue;
		}

	}

	system("pause");
	return 0;
}