#pragma once
#ifndef __RING_H__
#define __RING_H__

#include "Circle.h"

class Ring
{
private:
	Circle c1, c2;
public:
	void Init(int x1, int y1, int r1, int x2, int y2, int r2);
	void ShowRingInfo() const;
};

#endif // !__RING_H__
