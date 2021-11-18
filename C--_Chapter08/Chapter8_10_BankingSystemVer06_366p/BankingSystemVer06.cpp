/*
���� : Banking System ver06
��¥ : 2018-11-08
���� : NormalAccount(���뿹�ݰ���)�� HightCreditAccount(�ſ�ŷڰ���) Ŭ���� �߰�
*/

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;

const int NAME_LEN = 20;	// �̸� ����

/* 1:���»��� 2:�Ա� 3:��� 4:�������� ��ü ��� 5:���α׷� ���� */
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/* �ſ��� A,B,C */
enum CREDIT { A = 1, B, C };

/*
Ŭ���� �̸� : Account
Ŭ���� ���� : Entity Ŭ����
*/
class Account
{
private:
	int accID;			// ����ID
	int balance;		// �ܰ�
	char * cusName;		// �̸�
public:
	/*������*/
	Account(int ID, int money, const char * name);
	Account(const Account& ref);

	int GetAccID() const;	// ����ID ��ȯ
	virtual void Deposit(int money);	// �Ա�
	int Withdraw(int money);			// ���
	virtual void ShowAccInfo() const;	// �������� ���
	~Account();							// �Ҹ���
};

/*������*/
Account::Account(int ID, int money, const char * name) :accID(ID), balance(money)
{
	int len = strlen(name) + 1;
	cusName = new char[len];
	strcpy_s(cusName, len, name);
}

/*����ID ��ȯ*/
int Account::GetAccID() const
{
	return accID;
}

/*�Ա�*/
void Account::Deposit(int money)
{
	balance += money;
}

/*���*/
int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}

/*�������� ���*/
void Account::ShowAccInfo() const
{
	cout << "����ID: " << accID << endl;
	cout << "�� ��: " << cusName << endl;
	cout << "�� ��: " << balance << endl;
}

/* �Ҹ��� */
Account::~Account()
{
	delete[]cusName;
}

/*
Ŭ�����̸�: NormalAccount
Ŭ��������: ���뿹�ݰ���
*/
class NormalAccount : public Account
{
private:
	int rate;	// ������
public:
	/* ������ */
	NormalAccount(int ID, int money, const char * name, int myrate);

	virtual void ShowAccInfo() const;	// �������� ���
	virtual void Deposit(int money);	// �Ա�
};

/*������*/
NormalAccount::NormalAccount(int ID, int money, const char * name, int myrate)
	: Account(ID, money, name), rate(myrate)
{

}

/*�������� ���+(������ �߰�)*/
void NormalAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "������ : " << rate << endl;
}

/*�Ա�*/
void NormalAccount::Deposit(int money)
{
	Account::Deposit(money+(money*(((double)rate)/100)));	/* �Ա޾װ� �Ա޾��� �������� ����ؼ� 
															Account Ŭ������ Deposit �Լ��� balance ������ ����*/
}

class HightCreditAccount : public Account
{
private:
	int rate;	// ������
	int credit;	// �ſ���
public:
	HightCreditAccount(int ID, int money, const char * name, int myrate, int mycredit);
	virtual void ShowAccInfo() const;
	virtual void Deposit(int money);
};

HightCreditAccount::HightCreditAccount(int ID, int money, const char * name, int myrate, int mycredit)
	: Account(ID, money, name), credit(mycredit)
{
	/* A����̸� �Է¹��� �������� 7%, B����̸� 4%, C����̸� 2%�� ���Ѵ�.*/
	if (credit == 1)	// A���
	{
		rate = myrate+ 7;
	}
	else if (credit == 2)	// B���
	{
		rate = myrate+4;
	}
	else {	// C���
		rate = myrate+2;
	}
}

/*�������� ���+(������,�ſ���)*/
void HightCreditAccount::ShowAccInfo() const
{
	Account::ShowAccInfo();
	cout << "������ : " << rate << endl;
	cout << "�ſ��� : " << credit << endl;
}

/*�Ա�*/
void HightCreditAccount::Deposit(int money)
{
	Account::Deposit(money + (money*(((double)rate) / 100))); /* �Ա޾װ� �Ա޾��� �������� ����ؼ� 
															Account Ŭ������ Deposit �Լ��� balance ������ ����*/
}

/*
Ŭ�����̸� : AccountHandler
Ŭ�������� : ��Ʈ��(Control) Ŭ����
*/
class AccountHandler
{
private:
	Account * accArr[100];	// ������ �迭
	int accNum;				// ���� ����
public:
	AccountHandler(); // ������
	void ShowMenu(void) const;	// �޴�
	void MakeAccount(void);		// ���»���
	void DepositMoney(void);	// �Ա�
	void WithdrawMoney(void);	// ���
	void ShowAllAccInfo(void) const;	// �������� ��ü ���
	~AccountHandler();			// �Ҹ���
};

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount(void)
{
	int id;					// ���� ID
	char name[NAME_LEN];	// �̸�
	int balance;	// �ܰ�
	int choice;	// ���뿹��, �ſ�ŷ� ���� ����
	int rate;	// ������
	int credit;	// �ſ���
	
	cout << "[������������]" << endl;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> choice;

	if (choice == 1)
	{
		cout << "[���뿹�ݰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: ";cin >> balance;
		cout << "������: "; cin >> rate;
		cout << endl;

		accArr[accNum++] = new NormalAccount(id, balance, name, rate);	// ���뿹�ݰ��� ����
	}
	else if (choice == 2)
	{
		cout << "[�ſ�ŷڰ��� ����]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�� ��: "; cin >> name;
		cout << "�Աݾ�: ";cin >> balance;
		cout << "������: "; cin >> rate;
		cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> credit;
		cout << endl;
		accArr[accNum++] = new HightCreditAccount(id, balance, name, rate,credit);	// �ſ뿹�ݰ��� ����
	}
	else {
		cout << "1���� 2���߿� �������ּ���" << endl;
		return;
	}
}

/*�Ա�*/
void AccountHandler::DepositMoney(void)
{
	int money;	// �Ա޾�
	int id;	// �Է¹��� ����ID ����
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "�Աݾ�: "; cin >> money;

	for (int i = 0;i < accNum;i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);	// �Ա޾� �Ա�
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

/*���*/
void AccountHandler::WithdrawMoney(void)
{
	int money;	// ��ݾ�
	int id;	// �Է¹��� ����ID ����
	cout << "[��   ��]" << endl;
	cout << "����ID: "; cin >> id;
	cout << "��ݾ�: "; cin >> money;

	for (int i = 0;i < accNum;i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl << endl;
}

/*������*/
AccountHandler::AccountHandler() :accNum(0)
{

}

/*�������� ��ü ���*/
void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0;i < accNum;i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

/*�Ҹ���*/
AccountHandler::~AccountHandler()
{
	for (int i = 0;i < accNum;i++)
		delete accArr[i];
}

/*
��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�
*/

int main(void)
{
	AccountHandler manager;	// AccountHandler Ŭ������ ��ü
	int choice;	// �޴� ��ȣ���� ����

	while (1)
	{
		manager.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}