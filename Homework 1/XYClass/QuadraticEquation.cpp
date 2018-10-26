#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(int a, int b, int c) :a(a), b(b), c(c) {}

int QuadraticEquation::getA() const
{
	std::cout << a << std::endl;
	return a;
}

int QuadraticEquation::getB() const
{
	std::cout << b << std::endl;
	return b;
}

int QuadraticEquation::getC() const
{
	std::cout << c << std::endl;
	return c;
}

int QuadraticEquation::getDiscriminant()
{
	int ret = b * b - 4 * a * c;
	std::cout << ret << std::endl;
	return ret;
}

double QuadraticEquation::getRoot1()
{
	if (b * b - 4 * a * c < 0)
	{
		std::cout << "0" << std::endl;
		return 0;
	}
	else if (a > 0)
	{
		double ret = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		if (ret == -0.00000)
			ret = 0.0;
		std::cout << ret << std::endl;
		return ret;
	}
	else
	{
		double ret = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (ret == -0.00000)
			ret = 0.0;
		std::cout << ret << std::endl;
		return ret;
	}
}

double QuadraticEquation::getRoot2()
{
	if (b * b - 4 * a * c < 0)
	{
		std::cout << "0" << std::endl;
		return 0;
	}
	else if (a > 0)
	{
		double ret = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		if (ret == -0.00000)
			ret = 0.0;
		std::cout << ret << std::endl;
		return ret;
	}
	else
	{
		double ret = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		if (ret == -0.00000)
			ret = 0.0;
		std::cout << ret << std::endl;
		return ret;
	}
}