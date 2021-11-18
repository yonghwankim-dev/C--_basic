/*
파일이름: HightCreditAccount.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/

#ifndef __HIGHTCREDIT_ACCOUNT_H__
#define __HIGHTCREDIT_ACCOUNT_H__

#include "Account.h"

class HightCreditAccount : public Account
{
private:
	int rate;	// 이자율
	int credit;	// 신용등급
public:
	HightCreditAccount(int ID, int money, const char * name, int myrate, int mycredit);
	virtual void ShowAccInfo() const;
	virtual void Deposit(int money);
};
#endif // !__HIGHTCREDIT_ACCOUNT_H__

