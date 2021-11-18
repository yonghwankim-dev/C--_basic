#include "bank.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;
using admin::account_create;
using admin::deposit;
using admin::withdraw;
using admin::all_seek;
using admin::show_menu;

cus * c[100];
int index = 0;					// ���»��� �ε���
int id;							// ����ݽ� ����ID �Էº���
int sum;						// ����ݾ� �Էº���
char namestr[100];

// ���»���
void admin::account_create(void)
{
	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�� ��: ";
	cin >> namestr;
	cout << "�Աݾ�: ";
	cin >> sum;

	if (sum < 0 || id<0)
	{
		return;
	}

	c[index] = new cus(id, namestr, sum);

	index++;
}

// �Ա�
void admin::deposit()
{
	cout << "[��	��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}

	for (int i = 0;i < index;i++)
	{
		if (c[i]->Get_accNum() == id)
		{
			c[i]->Set_Plus_balance(sum);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}

// ���
void admin::withdraw()
{
	cout << "[��	��]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}

	for (int i = 0;i < index;i++)
	{
		if (c[i]->Get_accNum() == id)
		{
			c[i]->Set_Minus_balance(sum);
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}
// ��ü�� �ܾ���ȸ
void admin::all_seek(void)
{
	for (int i = 0;i < index;i++)
	{
		cout << "����ID: " << c[i]->Get_accNum() << endl;
		cout << "�̸�: " << c[i]->Get_Name() << endl;
		cout << "�ܾ�: " << c[i]->Get_balance() << endl << endl;
	}
}

// �޴�
void admin::show_menu(void)
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� : ";
}

// �� ��ü ������
cus::cus(int myAccNum, const char * myname, int mybalance):accNum(myAccNum),balance(mybalance)
{
	int len = strlen(myname) + 1;
	name = new char[len];
	strcpy_s(name, len, myname);
}

// �� ��ü ���������
cus::cus(const cus &ref) : accNum(ref.accNum), balance(ref.balance)
{
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);
}

// ����ID ��ȯ
int cus::Get_accNum()
{
	return cus::accNum;
}

// �Ա�
void cus::Set_Plus_balance(int sum)
{
	if (sum < 0)
	{
		cout << "0���� ū ���� �Է����ּ���" << endl;
		return;
	}
	cus::balance += sum;
}

// ����
void cus::Set_Minus_balance(int sum)
{
	if (cus::balance - sum < 0)
	{
		cout << "�ܾ��� �����մϴ�." << endl;
		return;
	}
	cus::balance -= sum;
}

// �̸� ��ȯ
char* cus::Get_Name()
{
	return cus::name;
}

// �ܾ� ��ȯ
int cus::Get_balance()
{
	if (cus::balance < 0)
	{
		cout << "���� �ܾ��� �����ϴ�." << endl;
		return 0;
	}

	return cus::balance;
}

// �Ҹ���
cus::~cus()
{
	delete[]cus::name;
	cout << "called destructor" << endl;
}

int main(void)
{
	int number;
	while (1)
	{
		show_menu();

		cin >> number;

		if (number == function::MAKE)
		{
			account_create();
		}
		else if (number == function::DEPOSIT)
		{
			deposit();
		}
		else if (number == function::WITHDRAW)
		{
			withdraw();
		}
		else if (number == function::INQUIRE)
		{
			all_seek();
		}
		else if (number == function::EXIT)
		{
			for (int i = 0;i < index;i++)
			{
				delete c[i];
				cout << "called destructor" << endl;
			}
			cout << "���α׷� ����" << endl;
			break;
		}
		else {
			continue;
		}

	}

	system("pause");
	return 0;
}