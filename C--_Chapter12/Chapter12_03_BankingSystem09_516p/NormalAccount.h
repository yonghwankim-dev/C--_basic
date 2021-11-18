/*
�����̸� : NormalAccount.h
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 09
*/


#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"
#include "String.h"

/*
Ŭ�����̸�: NormalAccount
Ŭ��������: ���뿹�ݰ���
*/
class NormalAccount : public Account
{
private:
	int rate;	// ������
public:
	/* ������ */
	NormalAccount(int ID, int money, String name, int myrate)
		:Account(ID, money, name), rate(myrate)
	{

	}
	//virtual void ShowAccInfo() const;	// �������� ���
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money*(rate / 100.0));
	}
};

#endif // !__NORMAL_ACCOUNT_H__
