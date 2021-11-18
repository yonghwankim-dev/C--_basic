#pragma once
/*
파일이름: HightCreditAccount.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/

#ifndef __HIGHTCREDIT_ACCOUNT_H__
#define __HIGHTCREDIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HightCreditAccount : public NormalAccount
{
private:
	int rate;
	int credit;
public:
	HightCreditAccount(int ID, int money, String name, int myrate, int mycredit)
		:NormalAccount(ID, money, name, myrate), credit(mycredit)
	{

	}
	//virtual void ShowAccInfo() const;
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money);
		Account::Deposit(money*(credit / 100.0));
	}
};
#endif // !__HIGHTCREDIT_ACCOUNT_H__

