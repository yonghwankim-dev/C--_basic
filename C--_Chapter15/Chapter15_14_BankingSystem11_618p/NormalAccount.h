/*
파일이름 : NormalAccount.h
작성자 : 김용환
업데이트 정보 : 2018-11-09 파일 버전 09
*/


#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__
#include "Account.h"
#include "String.h"

/*
클래스이름: NormalAccount
클래스유형: 보통예금계좌
*/
class NormalAccount : public Account
{
private:
	int rate;	// 이자율
public:
	/* 생성자 */
	NormalAccount(int ID, int money, String name, int myrate)
		:Account(ID, money, name), rate(myrate)
	{

	}
	//virtual void ShowAccInfo() const;	// 개인정보 출력
	virtual void Deposit(int money)
	{
		Account::Deposit(money);
		Account::Deposit(money*(rate / 100.0));
	}
};

#endif // !__NORMAL_ACCOUNT_H__
