#include "Cone.h"

Cone::Cone(double height, double radius) :Body(height), radius(radius) {}

void Cone::getArea()
{
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint)<< PI * radius * radius << endl;
	return;
}


void Cone::getVolume()
{
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint) << PI * radius * radius * height / 3 << endl;
	return;
}
