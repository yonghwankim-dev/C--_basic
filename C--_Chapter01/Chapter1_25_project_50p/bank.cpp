#include "bank.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

customer_info::cus c[100];
int index = 0;	// ���»��� �ε���
int id;			// ����ݽ� ����ID �Էº���
int sum;		// ����ݾ� �Էº���

// ���»���
void admin::account_create(void)
{
	cout << "[���°���]" << endl;
	
	cout << "����ID: ";
	cin >> c[index].accNum;
	cout << "�� ��: ";
	cin >> c[index].name;
	cout << "�Աݾ�: ";
	cin >> sum;

	if (sum < 0)
	{
		return;
	}
	c[index].balance += sum;

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
		if (c[i].accNum == id)
		{
			c[i].balance += sum;
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
		if (c[i].accNum == id)
		{
			c[i].balance -= sum;
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
		cout << "����ID: " << c[i].accNum << endl;
		cout << "�̸�: " << c[i].name << endl;
		cout << "�ܾ�: " << c[i].balance << endl<<endl;
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