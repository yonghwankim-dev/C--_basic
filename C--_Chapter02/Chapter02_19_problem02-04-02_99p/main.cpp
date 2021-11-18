#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

void set_rand(int arr[])
{
	srand((unsigned int)time(0));

	for (int i = 0;i < 5;i++)
	{
		arr[i] = rand() % 100;
	}
}

void show(int arr[])
{
	for (int i = 0;i < 5;i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

int main(void)
{
	int arr[5];

	set_rand(arr);
	show(arr);
	
	system("pause");
	return 0;
}
