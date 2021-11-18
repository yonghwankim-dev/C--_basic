/*
����: ���߻���� ��ȣ��
*/
#include <iostream>

using std::cout;
using std::endl;

class BaseOne
{
public:
	void SimpleFunc()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFunc()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, public BaseTwo
{
public:
	void ComplexFunc()
	{
		BaseOne::SimpleFunc();
		BaseTwo::SimpleFunc();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();

	system("pause");
	return 0;
}