#include "bank.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

customer_info::cus c[100];
int index = 0;	// 계좌생성 인덱스
int id;			// 입출금시 계좌ID 입력변수
int sum;		// 입출금액 입력변수

// 계좌생성
void admin::account_create(void)
{
	cout << "[계좌개설]" << endl;
	
	cout << "계좌ID: ";
	cin >> c[index].accNum;
	cout << "이 름: ";
	cin >> c[index].name;
	cout << "입금액: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}
	c[index].balance += sum;

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
		if (c[i].accNum == id)
		{
			c[i].balance += sum;
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
		if (c[i].accNum == id)
		{
			c[i].balance -= sum;
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
		cout << "계좌ID: " << c[i].accNum << endl;
		cout << "이름: " << c[i].name << endl;
		cout << "잔액: " << c[i].balance << endl<<endl;
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