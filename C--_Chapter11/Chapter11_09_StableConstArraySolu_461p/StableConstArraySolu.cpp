#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}		// ���� �����ڸ� ���� ���� ��ó
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}	// ���� �����ڸ� ���� ���� ��ó
																	// ������ �迭�� ����Ҹ� �����ϴ� ���� ���� ���ؼ��̴�.
public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int& operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrlen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete[]arr;
	}
};

void ShowAllData(const BoundCheckIntArray& ref)
{
	int len = ref.GetArrlen();
	for (int idx = 0; idx < len;idx++)
	{
		cout << ref[idx] << endl;
	}
}

int main(void)
{
	BoundCheckIntArray arr(5);
	for (int i = 0;i < 5;i++)
	{
		arr[i] = (i + 1) * 11;
	}

	ShowAllData(arr);

	system("pause");
	return 0;
}