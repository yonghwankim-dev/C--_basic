#pragma once
#ifndef __BANK__H__
#define __BANK__H__

namespace function
{
	enum {
		MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT
	};
}

namespace admin
{
	void account_create(void);
	void deposit(void);
	void withdraw(void);
	void all_seek(void);
	void show_menu(void);
}

class cus
{
private:
	int accNum;
	char *name;
	int balance;
public:
	cus(int myAccNum, const char * myname, int mybalance);
	cus(const cus &ref);
	~cus();
	int Get_accNum()const;
	char* Get_Name()const;
	int Get_balance()const;
	void Set_Plus_balance(int sum);
	void Set_Minus_balance(int sum);

};



#endif