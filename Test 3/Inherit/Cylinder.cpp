#include "Cylinder.h"

Cylinder::Cylinder(double height, double radius) :Body(height), radius(radius) {}

void Cylinder::getArea()
{
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint) << PI * radius * radius << endl;
	return;
}


void Cylinder::getVolume()
{
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint) << PI * radius * radius * height << endl;
	return;
}
