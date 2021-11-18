/*
제목: 다중상속의 기본방법
*/
#include <iostream>

using std::cout;
using std::endl;

class BaseOne
{
public:
	void SimpleFuncOne()
	{
		cout << "BaseOne" << endl;
	}
};

class BaseTwo
{
public:
	void SimpleFuncTwo()
	{
		cout << "BaseTwo" << endl;
	}
};

class MultiDerived : public BaseOne, public BaseTwo
{
public:
	void ComplexFunc()
	{
		SimpleFuncOne();
		SimpleFuncTwo();
	}
};

int main(void)
{
	MultiDerived mdr;
	mdr.ComplexFunc();
	
	system("pause");
	return 0;
}