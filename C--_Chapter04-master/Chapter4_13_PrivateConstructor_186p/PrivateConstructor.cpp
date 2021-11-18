#include <iostream>	
using std::cout;
using std::endl;

class AAA
{
private:
	int num;
public:
	AAA() :num(0){}
	AAA& CreateInitObj(int n) const
	{
		AAA *ptr = new AAA(n);
		return *ptr;
	}
	void showNum() const
	{
		cout << num << endl;
	}
private:
	AAA(int n):num(n){}
};

int main(void)
{
	AAA base;
	base.showNum();

	AAA &obj1 = base.CreateInitObj(3);
	obj1.showNum();

	AAA &obj2 = base.CreateInitObj(12);
	obj2.showNum();

	delete &obj1;
	delete &obj2;

	system("pause");
	return 0;
}