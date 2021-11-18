#include <iostream>

using std::cout;
using std::endl;

void add(int &ref)
{
	ref++;
}

void reverse(int &ref)
{
	ref = ref * -1;
}

int main(void)
{
	int val = 0;

	add(val);
	cout << val<<endl;

	reverse(val);
	cout << val << endl;

	system("pause");
	return 0;
}