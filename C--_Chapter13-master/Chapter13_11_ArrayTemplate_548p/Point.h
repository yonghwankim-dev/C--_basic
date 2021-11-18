#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

using std::ostream;


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	friend ostream& operator<<(ostream& os, const Point& pos);
};
#endif // !__POINT_H__
