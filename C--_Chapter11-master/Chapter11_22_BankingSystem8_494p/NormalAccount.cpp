/*
파일이름: NormalAccount.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/
#include <iostream>
#include <cstring>
#include "NormalAccount.h"

using std::endl;
using std::cout;

/*생성자*/
NormalAccount::NormalAccount(int ID, int money, const char * name, int myrate)
	: Account(ID, money, name), rate(myrate)
{

}

/*개인정보 출력+(이자율 추가)*/
void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "이자율 : " << rate << endl;
}

/*입금*/
void NormalAccount::Deposit(int money)
{
	/* 입급액과 입급액의 이자율을 계산해서 Account 클래스의 Deposit 함수의 balance 변수에 대입*/
	Account::Deposit(money + (money*(((double)rate) / 100)));
}
