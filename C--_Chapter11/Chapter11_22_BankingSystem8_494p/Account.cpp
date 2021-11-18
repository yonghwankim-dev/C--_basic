/*
�����̸�: Account.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/
#include <iostream>
#include <cstring>
#include "Account.h"
#include "BankingCommonDecl.h"

/*������*/
Account::Account(int ID, int money, const char * name) :accID(ID), balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, name);
}

Account& Account::operator=(const Account& ref)
{
	accID = ref.accID;
	balance = ref.balance;

	delete[]cusName;
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy_s(cusName, strlen(ref.cusName) + 1, ref.cusName);
	return *this;
}

/*����ID ��ȯ*/
int Account::GetAccID() const
{
	return accID;
}

/*�Ա�*/
void Account::Deposit(int money)
{
	balance += money;
}

/*���*/
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

/*�������� ���*/
void Account::ShowAccInfo() const
{
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}

/* �Ҹ��� */
Account::~Account()
{
	delete[]cusName;
}