#include <iostream>
using std::cout;
using std::endl;

template <class T>
T SumArray(T arr[], int len)
{
	T sum = (T)0;
	for (int i = 0;i < len;i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int arr1[] = { 10,20,30 };
	double arr2[] = { 10.3,10.4,10.5 };


	cout << SumArray(arr1, sizeof(arr1)/sizeof(int)) << endl;
	cout << SumArray(arr2, sizeof(arr2)/sizeof(double))<< endl;

	system("pause");
	return 0;
	

	
}