#include "ThreePrism.h"

ThreePrism::ThreePrism(double height, double a, double b, double c) :Body(height), side_a(a), side_b(b), side_c(c) {}

void ThreePrism::getArea()
{
	double p = side_a + side_b + side_c;
	p = p / 2;
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint) << sqrt(p * (p - side_a) * (p - side_b) * (p - side_c)) << endl;
	return;
}

void ThreePrism::getVolume()
{
	double p = side_a + side_b + side_c;
	p = p / 2;
	cout << setprecision(3) << std::setiosflags(ios::fixed | ios::showpoint) << sqrt(p * (p - side_a) * (p - side_b) * (p - side_c)) * height << endl;
	return;
}

