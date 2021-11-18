#include <iostream>

using std::cout;
using std::endl;

class Number
{
private:
	int num;
public:
	Number(int n) : num(n)
	{

	}
	void ShowData()
	{
		cout << num << endl;
	}

	Number* operator->()
	{
		return this;
	}
	Number& operator*()
	{
		return *this;
	}
};

int main(void)
{
	Number num(20);
	num.ShowData();

	(*num) = 30;
	num->ShowData();
	(*num).ShowData();

	system("pause");
	return 0;
}