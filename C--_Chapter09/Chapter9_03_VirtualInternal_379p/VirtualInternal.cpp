/*
제목: 가상함수의 동작원리와 가상함수 테이블
*/
#include <iostream>

using std::cout;
using std::endl;

class AAA
{
private:
	int num1;
public:
	virtual void Func1()
	{
		cout << "Func1" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2" << endl;
	}
};

class BBB : public AAA
{
private:
	int num2;
public:
	virtual void Func1() {
		cout << "BBB::Func1" << endl;
	}
	void Func3()
	{
		cout << "Func3" << endl;
	}
};

int main(void)
{
	AAA * aptr = new AAA();
	aptr->Func1();

	BBB * bptr = new BBB();
	bptr->Func1();

	system("pause");
	return 0;
}