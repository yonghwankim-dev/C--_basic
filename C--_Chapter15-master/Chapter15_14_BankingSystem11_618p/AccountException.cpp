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
	cout << "[���� �޽���: ��(��)�ݾ� " << reqDep << "�� ��ȿ���� �ʽ��ϴ�.]" << endl;
}

InsuffException::InsuffException(int wmoney) : money(wmoney)
{

}

void InsuffException::ShowExceptionReason()
{
	cout << "[���� �޽���: �ܾ׿��� " << money << "��(��) �����մϴ�.]" << endl;
}
