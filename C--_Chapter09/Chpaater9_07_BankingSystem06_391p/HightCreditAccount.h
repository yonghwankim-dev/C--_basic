/*
�����̸�: HightCreditAccount.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/

#ifndef __HIGHTCREDIT_ACCOUNT_H__
#define __HIGHTCREDIT_ACCOUNT_H__

#include "Account.h"

class HightCreditAccount : public Account
{
private:
	int rate;	// ������
	int credit;	// �ſ���
public:
	HightCreditAccount(int ID, int money, const char * name, int myrate, int mycredit);
	virtual void ShowAccInfo() const;
	virtual void Deposit(int money);
};
#endif // !__HIGHTCREDIT_ACCOUNT_H__

