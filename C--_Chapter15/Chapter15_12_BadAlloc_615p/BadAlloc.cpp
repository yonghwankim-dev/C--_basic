#include <iostream>
#include <new>	
using std::cout;
using std::endl;
using std::bad_alloc;

int main(void)
{
	int num = 0;

	try {
		while (1)
		{
			num++;
			cout << num << "��° �Ҵ� �õ�" << endl;
			new int[10000][10000];
			
		}
	}
	catch (bad_alloc &bad)
	{
		cout << bad.what() << endl;
		cout << "�� �̻� �Ҵ� �Ұ�!" << endl;
	}

	system("pause");
	return 0;
}