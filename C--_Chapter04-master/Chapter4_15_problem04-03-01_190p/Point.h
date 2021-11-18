#pragma once
#ifndef __POINT_H_
#define __POINT_H_

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y);
	void ShowPointInfo() const;
	int Get_X() const;
	int Get_Y() const;
	bool Set_X(int x);
	bool Set_Y(int y);
};
#endif // !__POINT_H_
