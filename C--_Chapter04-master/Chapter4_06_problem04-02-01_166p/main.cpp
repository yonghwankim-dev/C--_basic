#include "Ring.h"
#include <iostream>

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();

	system("pause");
	return 0;
}