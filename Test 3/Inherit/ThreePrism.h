#pragma once
#include "Body.h"

class ThreePrism :public Body
{
private:
	double side_a;
	double side_b;
	double side_c;
public:
	ThreePrism() = default;
	ThreePrism(double height, double a, double b, double c);
	void getArea();
	void getVolume();
	~ThreePrism() {}
};