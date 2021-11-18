#include <iostream>

using std::cout;
using std::endl;

int main(void)
{
	int num = 10;
	int *ptr = &num;
	int **dptr = &ptr;

	int &ref = num;
	int *(&pref) = ptr;
	int **(&dpref) = dptr;

	cout << ref << endl;
	cout << *pref << endl;
	cout << **dpref << endl;

	system("pause");
	return 0;
}
