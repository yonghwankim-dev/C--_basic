#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *temp = new Point;
	temp->xpos = p1.xpos + p2.xpos;
	temp->ypos = p1.ypos + p2.ypos;

	return *temp;
}
int main(void)
{
	Point *p1 = new Point;
	Point *p2 = new Point;

	p1->xpos = 10;
	p1->ypos = 10;

	p2->xpos = 20;
	p2->ypos = 20;

	const Point &p3 = PntAdder(*p1, *p2);

	cout << "p3.xpos : " << p3.xpos << endl;
	cout << "p3.ypos : " << p3.ypos << endl;

	delete p1;
	delete p2;

	system("pause");
	return 0;
}