#include "Circle.h"
#include <iostream>

using std::cout;
using std::endl;

void Circle::Init(int x, int y, int r)
{
	Set_X(x);
	Set_Y(y);
	Set_R(r);
}
void Circle::ShowCircleInfo() const
{
	cout << "radius:" << Get_R() << endl;
	point.ShowPointInfo();
}

int Circle::Get_X() const
{
	return point.Get_X();
}
int Circle::Get_Y() const
{
	return point.Get_Y();
}
int Circle::Get_R() const
{
	return radius;
}
bool Circle::Set_X(int x)
{
	point.Set_X(x);
	return true;
}
bool Circle::Set_Y(int y)
{
	point.Set_Y(y);
	return true;
}
bool Circle::Set_R(int r)
{
	radius = r;
	return true;
}