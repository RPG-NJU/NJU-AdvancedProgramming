#include "MyPoint.h"

MyPoint::MyPoint()
{
	x = 0;
	y = 0;
}

MyPoint::MyPoint(int x, int y):x(x),y(y) {}

int MyPoint::getX() const
{
	cout << x << endl;
	return x;
}

int MyPoint::getY() const
{
	cout << y << endl;
	return y;
}

double MyPoint::distance(const MyPoint p)
{
	if (this->x == p.x && this->y == p.y)
	{
		cout << "0" << endl;
		return 0;
	}
	else
	{
		double res = 0;
		res = sqrt((this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y));
		cout << res << endl;
		return res;
	}
}

double MyPoint::distance(int x, int y)
{
	if (this->x == x && this->y == y)
	{
		cout << "0" << endl;
		return 0;
	}
	else
	{
		double res = 0;
		res = sqrt((this->x - x) * (this->x - x) + (this->y - y) * (this->y - y));
		cout << res << endl;
		return res;
	}
}






