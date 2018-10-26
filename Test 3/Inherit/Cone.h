#pragma once
#include "Body.h"

class Cone :public Body
{
private:
	double radius;
public:
	Cone() = default;
	Cone(double height, double radius);
	void getArea();
	void getVolume();
	~Cone() {}
};
