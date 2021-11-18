/*
�����̸�: NormalAccount.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/

#include "Account.h"
#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HightCreditAccount.h"
#include "BankingCommonDecl.h"
#include "String.h"
#include <iostream>
#include <cstring>

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;					// ���� ID
	String name;	// �̸�
	int balance;	// �ܰ�
	int choice;	// ���뿹��, �ſ�ŷ� ���� ����
	int rate;	// ������
	int credit;	// �ſ���

	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> choice;

	if (choice == 1)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: ";cin >> balance;
		cout << "������: "; cin >> rate;
		cout << endl;

		accArr[accNum++] = new NormalAccount(id, balance, name, rate);	// ���뿹�ݰ��� ����
	}
	else if (choice == 2)
	{
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: ";cin >> balance;
		cout << "������: "; cin >> rate;
		cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> credit;
		cout << endl;
		accArr[accNum++] = new HightCreditAccount(id, balance, name, rate, credit);	// �ſ뿹�ݰ��� ����
	}
	else {
		cout << "1���� 2���߿� �������ּ���" << endl;
		return;
	}
}

/*�Ա�*/
void AccountHandler::DepositMoney(void)
{
	int money;	// �Ա޾�
	int id;	// �Է¹��� ����ID ����
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0;i < accNum;i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);	// �Ա޾� �Ա�
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

/*���*/
void AccountHandler::WithdrawMoney(void)
{
	int money;	// ��ݾ�
	int id;	// �Է¹��� ����ID ����
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0;i < accNum;i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

/*������*/
AccountHandler::AccountHandler() :accNum(0)
{

}

/*�������� ��ü ���*/
void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0;i < accNum;i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

/*�Ҹ���*/
AccountHandler::~AccountHandler()
{
	for (int i = 0;i < accNum;i++)
		delete accArr[i];
}
