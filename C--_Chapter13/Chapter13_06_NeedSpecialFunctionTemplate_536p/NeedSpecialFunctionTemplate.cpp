#include <iostream>	
using std::endl;
using std::cout;

template <typename T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;
	cout << Max("Simple", "Best") << endl;	// �ܼ��� �ּҰ��� ũ��񱳸� �ϰԵȴ�.

	system("pause");
	return 0;
}