#include "Body.h"

Body::Body(double height):height(height){}

void Body::printHeight()
{
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint)<<height << endl;
	return;
}

