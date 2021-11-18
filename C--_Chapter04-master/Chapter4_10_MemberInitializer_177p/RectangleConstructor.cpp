#include <iostream>
#include "Point.h"
#include "Rectangle.h"

using std::cout;
using std::endl;

int main(void)
{
	Rectangle rec(1, 1, 5, 5);
	rec.ShowRecInfo();

	system("pause");
	return 0;
}