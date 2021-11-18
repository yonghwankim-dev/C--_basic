#include <iostream>
using std::endl;
using std::cout;
using std::ostream;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	friend ostream& operator<<(ostream& os, const Point& pos);

	void * operator new(size_t size)	// new 와 delete는 static 함수이다.
	{
		cout << "operator new : " << size << endl;
		void * adr = new char[size];
		return adr;
	}
	void operator delete(void * adr)
	{
		cout << "operator delete ()" << endl;
		delete[]adr;
	}
};

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos<<']' << endl;
	return os;
}

int main(void)
{
	Point * ptr = new Point(3, 4);	// new와 delete 함수는 객체를 먼저 생성하지 않아도 static 함수이기때문에 static 함수로 실행이 가능하다.
	cout << *ptr;
	delete ptr;
	
	system("pause");
	return 0;
}