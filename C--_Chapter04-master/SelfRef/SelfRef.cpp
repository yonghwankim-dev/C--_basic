#include <iostream>
using std::endl;
using std::cout;

class SelfRef
{
private:
	int num;
public:
	SelfRef(int n) :num(n)
	{
		cout << "°´Ã¼»ı¼º" << endl;
	}
	SelfRef& Adder(int n)
	{
		num += n;
		return *this;
	}
	SelfRef& ShowTwoNumber()
	{
		cout << num << endl;
		return *this;
	}
};

int main(void)
{
	SelfRef obj(3);
	SelfRef &ref = obj.Adder(2);

	obj.ShowTwoNumber();
	ref.ShowTwoNumber();

	ref.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();

	system("pause");
	return 0;
}