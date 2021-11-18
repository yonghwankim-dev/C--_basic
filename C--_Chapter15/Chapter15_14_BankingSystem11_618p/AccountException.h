#ifndef __ACCOUNT_EXCPETION_H_
#define __ACCOUNT_EXCPETION_H_

class AccountException
{
public:
	virtual void ShowExceptionReason() = 0;
};

class MinusException : public AccountException
{
private:
	int reqDep;	// ��û �Աݾ�
public:
	MinusException(int money);
	void ShowExceptionReason();
};

class InsuffException : public AccountException
{
private:
	int money;
public:
	InsuffException(int wmoney);
	void ShowExceptionReason();
};

#endif // !__ACCOUNT_EXCPETION_H_
