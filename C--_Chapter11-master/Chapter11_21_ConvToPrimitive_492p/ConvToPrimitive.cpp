#include <iostream>
using std::cout;
using std::endl;

class Number
{
private:
	int num;
public:
	Number(int n = 0) : num(n)
	{
		cout << "Number(int n=0)" << endl;
	}
	Number& operator=(const Number& ref)
	{
		cout << "operator=()" << endl;
		num = ref.num;
		return *this;
	}
	operator int()	// 형 변환 연산자의 오버로딩
	{
		return num;
	}
	void ShowNumber()
	{
		cout << num << endl;
	}
};

int main(void)
{
	Number num;
	num = 30;
	Number num2 = num + 20;
	num2.ShowNumber();
	system("pause");
	return 0;
}