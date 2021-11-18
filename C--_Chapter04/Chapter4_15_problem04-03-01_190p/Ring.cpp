#include "Ring.h"
#include <iostream>

using std::cout;
using std::endl;

Ring::Ring(int x1, int y1, int r1, int x2, int y2, int r2):c1(x1,y1,r1),c2(x2,y2,r2){}
void Ring::ShowRingInfo() const
{
	cout << "Inner Circle Info..." << endl;
	c1.ShowCircleInfo();
	cout << "Outter Circle Info..." << endl;
	c2.ShowCircleInfo();
}