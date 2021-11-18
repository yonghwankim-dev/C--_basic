/*
�����̸� : NormalAccount.h
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/


#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"

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
	NormalAccount(int ID, int money, const char * name, int myrate);

	virtual void ShowAccInfo() const;	// �������� ���
	virtual void Deposit(int money);	// �Ա�
};

#endif // !__NORMAL_ACCOUNT_H__
