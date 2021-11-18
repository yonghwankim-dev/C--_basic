/*
�����̸�: Account.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 09
*/
#include <iostream>
#include <cstring>
#include "Account.h"
#include "BankingCommonDecl.h"

/*������*/
Account::Account(int ID, int money,String name) :accID(ID), balance(money)
{
	cusName = name;
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