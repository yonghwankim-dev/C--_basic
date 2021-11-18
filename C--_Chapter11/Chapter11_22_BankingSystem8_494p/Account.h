/*
�����̸� : Account.h
�ۼ��� : ���ȯ
������Ʈ ���� : 2019-02-08 ���� ���� 08
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/*
Ŭ���� �̸� : Account
Ŭ���� ���� : Entity Ŭ����
*/
class Account
{
private:
	int accID;			// ����ID
	int balance;		// �ܰ�
	char * cusName;		// �̸�
public:
	/*������*/
	Account(int ID, int money, const char * name);
	Account(const Account& ref);
	Account& operator=(const Account& ref);

	int GetAccID() const;	// ����ID ��ȯ
	virtual void Deposit(int money);	// �Ա�
	int Withdraw(int money);			// ���
	virtual void ShowAccInfo() const;	// �������� ���
	~Account();							// �Ҹ���
};

#endif // !__ACCOUNT_H__

