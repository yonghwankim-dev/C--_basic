#include "PointTemplate.h"
#include "PointTemplate.cpp"	// 이 문장을 넣어야 실행이 된다.
								// 이 문장이 없으면 컴파일러는 클래스 템플릿인 Point에 대한 정보가 부족해진다.
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();

	Point<double> pos2(2.4, 3.6);
	pos2.ShowPosition();

	Point<char> pos3('P', 'F');
	pos3.ShowPosition();

	system("pause");
	return 0;
}