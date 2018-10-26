#pragma once
#include "Body.h"

class Cylinder :public Body
{
private:
	double radius;
public:
	Cylinder() = default;
	Cylinder(double height, double radius);
	void getArea();
	void getVolume();
	~Cylinder() {}
};
