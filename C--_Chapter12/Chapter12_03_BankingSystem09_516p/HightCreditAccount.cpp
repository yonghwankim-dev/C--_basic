/*
�����̸�: NormalAccount.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���� ���� 07
*/
#include <iostream>
#include <cstring>
#include "HightCreditAccount.h"

using std::endl;
using std::cout;


/*
HightCreditAccount::HightCreditAccount(int ID, int money, String name, int rate, int mycredit)
	: NormalAccount(ID, money, name,rate), credit(mycredit)
{
	*/
	/* A����̸� �Է¹��� �������� 7%, B����̸� 4%, C����̸� 2%�� ���Ѵ�.*/
/*
	if (credit == 1)	// A���
	{
		rate = rate + 7;
	}
	else if (credit == 2)	// B���
	{
		rate = rate + 4;
	}
	else {	// C���
		rate = rate + 2;
	}
}
*/

/*�������� ���+(������,�ſ���)*/
/*
void HightCreditAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "������ : " << rate << endl;
	cout << "�ſ��� : " << credit << endl;
}*/

/*�Ա�*/
//void HightCreditAccount::Deposit(int money)
//{
//	/* �Ա޾װ� �Ա޾��� �������� ����ؼ� Account Ŭ������ Deposit �Լ��� balance ������ ����*/
//	Account::Deposit(money + (money*(((double)rate) / 100)));
//}