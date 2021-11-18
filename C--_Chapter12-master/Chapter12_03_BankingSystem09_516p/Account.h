/*
�����̸� : Account.h
�ۼ��� : ���ȯ
������Ʈ ���� : 2019-02-08 ���� ���� 09
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
Ŭ���� �̸� : Account
Ŭ���� ���� : Entity Ŭ����
*/
class Account
{
private:
	int accID;			// ����ID
	int balance;		// �ܰ�
	String cusName;		// �̸�
public:
	/*������*/
	Account(int ID, int money, String name);

	int GetAccID() const;	// ����ID ��ȯ
	virtual void Deposit(int money);	// �Ա�
	int Withdraw(int money);			// ���
	virtual void ShowAccInfo() const;	// �������� ���
};

#endif // !__ACCOUNT_H__

