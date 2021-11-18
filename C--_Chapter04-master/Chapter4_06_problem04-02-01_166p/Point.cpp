#include "Point.h"
#include <iostream>

using std::cout;
using std::endl;

void Point::Init(int x, int y)
{
	xpos = x;
	ypos = y;
}
void Point::ShowPointInfo() const
{
	cout << "[" << xpos << ", " << ypos << "]" << endl;
}
int Point::Get_X() const
{
	return xpos;
}
int Point::Get_Y() const
{
	return ypos;
}
bool Point::Set_X(int x)
{
	xpos = x;
	return true;
}
bool Point::Set_Y(int y)
{
	ypos = y;
	return true;
}