#pragma once
#ifndef __CIRCLE_H_
#define __CIRCLE_H_

#include "Point.h"

class Circle
{
private:
	Point point;// 원의 중심좌표
	int radius;	// 반지름
public:
	void Init(int x, int y, int r);
	void ShowCircleInfo() const;
	int Get_X() const;
	int Get_Y() const;
	int Get_R() const;
	bool Set_X(int x);
	bool Set_Y(int y);
	bool Set_R(int r);
};
#endif // !__CIRCLE_H_
