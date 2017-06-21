#ifndef _POINT_H_
#define _POINT_H_

struct Point
{
	Point() {}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	int x, y;
};

#endif // !_POINT_H_

