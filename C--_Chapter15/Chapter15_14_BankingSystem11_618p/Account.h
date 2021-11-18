#pragma once
/*
파일이름 : Account.h
작성자 : 김용환
업데이트 정보 : 2019-02-08 파일 버전 09
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

/*
클래스 이름 : Account
클래스 유형 : Entity 클래스
*/
class Account
{
private:
	int accID;			// 계좌ID
	int balance;		// 잔고
	String cusName;		// 이름
public:
	/*생성자*/
	Account(int ID, int money, String name);
	int GetAccID() const;	// 계좌ID 반환
	virtual void Deposit(int money);	// 입금
	int Withdraw(int money);			// 출금
	virtual void ShowAccInfo() const;	// 개인정보 출력
	int GetBalance() const;	// 잔고 출력
};

#endif // !__ACCOUNT_H__

