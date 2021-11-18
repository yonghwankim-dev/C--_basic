#pragma once
/*
�����̸�: HightCreditAccount.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
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
		:NormalAccount(ID, money, name,myrate), credit(mycredit)
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

