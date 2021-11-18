#ifndef __POINT_H_
#define __POINT_H_


class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0);
	void SetPos(int x, int y);
	void ShowPosition() const;
};
#endif // !__POINT_H_
