/*
파일이름: AccountHandler.cpp
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 07
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__
#include "Account.h"

/*
클래스이름 : AccountHandler
클래스유형 : 컨트롤(Control) 클래스
*/
class AccountHandler
{
private:
	Account * accArr[100];	// 계좌의 배열
	int accNum;				// 계좌 갯수
public:
	AccountHandler(); // 생성자
	void ShowMenu(void) const;	// 메뉴
	void MakeAccount(void);		// 계좌생성
	void DepositMoney(void);	// 입급
	void WithdrawMoney(void);	// 출금
	void ShowAllAccInfo(void) const;	// 개인정보 전체 출력
	~AccountHandler();			// 소멸자
};
#endif // !__ACCOUNT_HANDLER_H__
