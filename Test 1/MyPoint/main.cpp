#include "MyPoint.h"

int main()
{
	MyPoint p;
	MyPoint pq(3, -2);
	pq.getX();
	pq.getY();
	pq.distance(p);
	p.distance(pq);
	return 0;
}