#include <iostream>
using std::cout;
using std::endl;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / Get_APPLE_PRICE();
		Set_numOfApples(Get_numOfApples() - num);
		Set_mymoney(Get_myMoney() + money);
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
	int Get_APPLE_PRICE() const
	{
		return APPLE_PRICE;
	}
	int Get_numOfApples() const
	{
		return numOfApples;
	}
	int Get_myMoney() const
	{
		return myMoney;
	}
	bool Set_APPLE_PRICE(int price)
	{
		if (price < 0) {
			cout << "��������� 0�̸����� ���� �� �� �����ϴ�." << endl;
			return false;
		}
		APPLE_PRICE = price;
		return true;
	}
	bool Set_numOfApples(int num)
	{
		if (num < 0) {
			cout << "��������� 0�̸����� ���� �� �� �����ϴ�." << endl;
			return false;
		}
		numOfApples = num;
		return true;
	}
	bool Set_mymoney(int money)
	{
		if (money < 0) {
			cout << "�����ݾ��� 0�̸����� ���� �� �� �����ϴ�." << endl;
			return false;
		}
		myMoney = money;
		return true;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money < 0)
		{
			cout << "0�̻��� ���� �Է����ּ���" << endl << endl;
			return;
		}
		Set_numOfApples(Get_numOfApples() + seller.SaleApples(money));
		Set_myMoney(Get_myMoney() - money);
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
	int Get_myMoney() const
	{
		return myMoney;
	}
	int Get_numOfApples() const
	{
		return numOfApples;
	}
	bool Set_myMoney(int money)
	{
		if (money < 0)
		{
			cout << "�����ݾ��� 0�̸����� ���� �� �� �����ϴ�." << endl;
			return false;
		}
		myMoney = money;
		return true;
	}
	bool Set_numOfApples(int num)
	{
		if (num < 0)
		{
			cout << "��������� 0�̸����� ���� �� �� �����ϴ�." << endl;
			return false;
		}
		numOfApples = num;
		return true;
	}
};

int main(void)
{
	FruitSeller seller(1000, 20, 0);
	FruitBuyer buyer(5000);
	buyer.BuyApples(seller, 2000);	// ���� ����

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	system("pause");
	return 0;
}