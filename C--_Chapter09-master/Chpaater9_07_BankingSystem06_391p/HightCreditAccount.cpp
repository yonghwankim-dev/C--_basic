/*
파일이름: NormalAccount.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/
#include <iostream>
#include <cstring>
#include "HightCreditAccount.h"

using std::endl;
using std::cout;



HightCreditAccount::HightCreditAccount(int ID, int money, const char * name, int myrate, int mycredit)
	: Account(ID, money, name), credit(mycredit)
{
	/* A등급이면 입력받은 이자율에 7%, B등급이면 4%, C등급이면 2%를 더한다.*/
	if (credit == 1)	// A등급
	{
		rate = myrate + 7;
	}
	else if (credit == 2)	// B등급
	{
		rate = myrate + 4;
	}
	else {	// C등급
		rate = myrate + 2;
	}
}

/*개인정보 출력+(이자율,신용등급)*/
void HightCreditAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "이자율 : " << rate << endl;
	cout << "신용등급 : " << credit << endl;
}

/*입급*/
void HightCreditAccount::Deposit(int money)
{
	/* 입급액과 입급액의 이자율을 계산해서 Account 클래스의 Deposit 함수의 balance 변수에 대입*/
	Account::Deposit(money + (money*(((double)rate) / 100)));
}