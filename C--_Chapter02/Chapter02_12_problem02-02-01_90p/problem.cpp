#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	const int num = 12;
	const int *ptr = &num;
	const int *(&ref) = ptr;

	cout << "num : " << num << endl;
	cout << "ptr : " << *ptr << endl;
	cout << "ref : " << *ref << endl;

	system("pause");
	return 0;
}