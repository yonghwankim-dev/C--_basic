#include <iostream>

using std::cout;
using std::endl;

template <typename T1, typename T2>
void ShowData(double num)
{
	cout << T1(num) << ", " << T2(num) << endl;
}

int main(void)
{
	ShowData<char, int>(65);
	ShowData<char, int>(67);
	ShowData<char, double>(68.9);
	ShowData<short, double>(69.2);
	ShowData<short, double>(70.4);

	system("pause");
	return 0;
}