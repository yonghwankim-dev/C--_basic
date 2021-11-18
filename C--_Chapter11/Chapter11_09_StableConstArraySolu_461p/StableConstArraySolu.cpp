#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

class BoundCheckIntArray
{
private:
	int * arr;
	int arrlen;
	BoundCheckIntArray(const BoundCheckIntArray& arr) {}		// 복사 생성자를 막기 위한 대처
	BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}	// 대입 연산자를 막기 위한 대처
																	// 이유는 배열의 저장소를 복사하는 것을 막기 위해서이다.
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