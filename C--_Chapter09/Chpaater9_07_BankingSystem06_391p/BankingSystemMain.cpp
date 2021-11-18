/*
����Ʈ���� ���� : Banking System Ver 0.7
�����̸� : BankingSystemMain.cpp
�ۼ��� : ���ȯ
������Ʈ ���� : 2018-11-09 ���Ϲ��� 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"


/*
��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�.
*/

int main(void)
{
	AccountHandler manager;	// AccountHandler Ŭ������ ��ü
	int choice;	// �޴� ��ȣ���� ����

	while (1)
	{
		manager.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}