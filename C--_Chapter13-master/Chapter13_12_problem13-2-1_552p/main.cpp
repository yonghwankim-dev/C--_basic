#include <iostream>
#include "SmartPtr.h"
#include "SmartPtr.cpp"
#include "Point.h"

int main(void)
{
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	system("pause");
	return 0;
}