#pragma once
#ifndef __BANK__H__
#define __BANK__H__

namespace admin
{
	void account_create(void);
	void deposit(void);
	void withdraw(void);
	void all_seek(void);
	void show_menu(void);
}

namespace customer_info
{
	typedef struct customer
	{
		int accNum;
		char name[100];
		int balance;
	} cus;
}



#endif