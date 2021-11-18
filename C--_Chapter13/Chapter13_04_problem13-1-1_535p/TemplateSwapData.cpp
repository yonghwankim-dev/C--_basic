#include <iostream>

using std::cout;
using std::endl;


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

template <class T>
void SwapData(T& p1, T& p2)
{
	T temp = p1;
	p1 = p2;
	p2 = temp;
	
}

int main(void)
{
	Point p1(1, 2), p2(3, 4);

	cout << "변경전 p1 : ";
	p1.ShowPosition();
	cout << "변경전 p2 : ";
	p2.ShowPosition();


	SwapData(p1,p2);

	cout << "변경후 p1 : ";
	p1.ShowPosition();
	cout << "변경후 p2 : ";
	p2.ShowPosition();

	system("pause");
	return 0;


}