#include <iostream>
using std::endl;
using std::cout;
template <typename T>

T Add(T num1, T num2)
{
	return num1 + num2;
}


int main(void)
{
	cout << Add<int>(15, 20) << endl;
	cout << Add<double>(2.9,3.7) << endl;
	cout << Add<int>(3.2,3.2) << endl;
	cout << Add<double>(3.14,2.75) << endl<<endl;


	cout << Add(15, 20) << endl;
	cout << Add(2.9, 3.7) << endl;
	cout << Add(3.2, 3.2) << endl;
	cout << Add(3.14, 2.75) << endl;

	system("pause");
	return 0;
}