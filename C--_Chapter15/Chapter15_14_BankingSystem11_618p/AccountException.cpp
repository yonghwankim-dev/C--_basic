#include <iostream>
#include "AccountException.h"
#include "Account.h"

using std::cout;
using std::endl;

MinusException::MinusException(int money) : reqDep(money)
{

}
void MinusException::ShowExceptionReason()
{
	cout << "[예외 메시지: 입(출)금액 " << reqDep << "은 유효하지 않습니다.]" << endl;
}

InsuffException::InsuffException(int wmoney) : money(wmoney)
{

}

void InsuffException::ShowExceptionReason()
{
	cout << "[예외 메시지: 잔액에서 " << money << "가(이) 부족합니다.]" << endl;
}
