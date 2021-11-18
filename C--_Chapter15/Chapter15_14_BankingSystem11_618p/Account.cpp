/*
�����̸�: Account.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 09
*/
#include <iostream>
#include <cstring>
#include "Account.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

/*������*/
Account::Account(int ID, int money, String name) :accID(ID), balance(money)
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
	if (money < 0)
		throw MinusException(money);
	balance += money;
}

/*���*/
int Account::Withdraw(int money)
{
	if (money < 0)
		throw MinusException(money);
	if (balance < money)
		throw InsuffException(money);
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

/*�ܰ� ���*/
int Account::GetBalance() const	// �ܰ� ���
{
	return balance;
}