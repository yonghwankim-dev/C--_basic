/*
소프트웨어 버전 : Banking System Ver 0.7
파일이름 : BankingSystemMain.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일버전 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"


/*
컨트롤 클래스 AccountHandler 중심으로 변경된 main 함수.
*/

int main(void)
{
	AccountHandler manager;	// AccountHandler 클래스의 객체
	int choice;	// 메뉴 번호선택 변수

	while (1)
	{
		manager.ShowMenu();
		cout << "선택: ";
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