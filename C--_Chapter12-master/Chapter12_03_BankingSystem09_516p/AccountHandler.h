/*
�����̸�: AccountHandler.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2019-02-08 ���� ���� 08
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "Account.h"
#include "AccountArray.h"
/*
Ŭ�����̸� : AccountHandler
Ŭ�������� : ��Ʈ��(Control) Ŭ����
*/
class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;
	int accNum;				// ���� ����
public:
	AccountHandler(); // ������
	void ShowMenu(void) const;	// �޴�
	void MakeAccount(void);		// ���»���
	void DepositMoney(void);	// �Ա�
	void WithdrawMoney(void);	// ���
	void ShowAllAccInfo(void) const;	// �������� ��ü ���
	~AccountHandler();			// �Ҹ���
};
#endif // !__ACCOUNT_HANDLER_H__
