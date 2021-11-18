#include "Point.h"
#include <iostream>

using std::endl;
using std::cout;

Point::Point(int x, int y):xpos(x),ypos(y)
{
	
}

void Point::SetPos(int x, int y)
{
	xpos = x;
	ypos = y;
}

void Point::ShowPosition() const
{
	cout << '[' << xpos << ", " << ypos << ']' << endl;
}