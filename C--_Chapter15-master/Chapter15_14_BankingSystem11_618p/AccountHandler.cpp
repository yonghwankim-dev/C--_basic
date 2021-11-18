/*
파일이름: NormalAccount.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/

#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HightCreditAccount.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

#include "String.h"
#include <iostream>
#include <cstring>

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;					// 계좌 ID
	String name;	// 이름
	int balance;	// 잔고
	int choice;	// 보통예금, 신용신뢰 계좌 선택
	int rate;	// 이자율
	int credit;	// 신용등급

	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: "; cin >> choice;

	if (choice == 1)
	{
		cout << "[보통예금계좌 개설]" << endl;
		cout << "계좌ID: "; cin >> id;
		cout << "이 름: "; cin >> name;
		cout << "입금액: ";cin >> balance;
		cout << "이자율: "; cin >> rate;
		cout << endl;

		accArr[accNum++] = new NormalAccount(id, balance, name, rate);	// 보통예금계좌 생성
	}
	else if (choice == 2)
	{
		cout << "[신용신뢰계좌 개설]" << endl;
		cout << "계좌ID: "; cin >> id;
		cout << "이 름: "; cin >> name;
		cout << "입금액: ";cin >> balance;
		cout << "이자율: "; cin >> rate;
		cout << "신용등급(1toA, 2toB, 3toC): "; cin >> credit;
		cout << endl;
		accArr[accNum++] = new HightCreditAccount(id, balance, name, rate, credit);	// 신용예금계좌 생성
	}
	else {
		cout << "1번과 2번중에 선택해주세요" << endl;
		return;
	}
}

/*입급*/
void AccountHandler::DepositMoney(void)
{
	int money;	// 입급액
	int id;	// 입력받을 계좌ID 변수
	cout << "[입   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "입금액: "; cin >> money;


	try {

		for (int i = 0;i < accNum;i++)
		{
			if (accArr[i]->GetAccID() == id)
			{
				accArr[i]->Deposit(money);	// 입급액 입금
				cout << "입금완료" << endl << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID입니다." << endl << endl;
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}
}

/*출금*/
void AccountHandler::WithdrawMoney(void)
{
	int money;	// 출금액
	int id;	// 입력받을 계좌ID 변수
	cout << "[출   금]" << endl;
	cout << "계좌ID: "; cin >> id;
	cout << "출금액: "; cin >> money;
	
	try {
		for (int i = 0;i < accNum;i++)
		{
			if (accArr[i]->GetAccID() == id)
			{
				accArr[i]->Withdraw(money);
				cout << "출금완료" << endl;
				return;
			}
		}
		cout << "유효하지 않은 ID입니다." << endl << endl;
	}
	catch (AccountException &expn)
	{
		expn.ShowExceptionReason();
	}

}


/*생성자*/
AccountHandler::AccountHandler() : accNum(0)
{

}


/*개인정보 전체 출력*/
void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0;i < accNum;i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

/*소멸자*/
AccountHandler::~AccountHandler()
{
	for (int i = 0;i < accNum;i++)
		delete accArr[i];
}
