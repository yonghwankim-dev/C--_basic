#include <iostream>
#include "bank.h"
using std::cout;
using std::cin;
using std::endl;

using admin::account_create;
using admin::deposit;
using admin::withdraw;
using admin::all_seek;
using admin::show_menu;

int main(void)
{
	int number;
	while (1)
	{
		show_menu();

		cin >> number;

		if (number == 1)
		{
			account_create();
		}
		else if (number == 2)
		{
			deposit();
		}
		else if (number == 3)
		{
			withdraw();
		}
		else if (number == 4)
		{
			all_seek();
		}
		else if (number == 5)
		{
			cout << "프로그램 종료" << endl;
			return 0;
		}
		else {
			continue;
		}

	}

	system("pause");
	return 0;
}