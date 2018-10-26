#include "QuadraticEquation.h"

int main()
{
	QuadraticEquation p(1, -2, 0);

	int a = p.getA();

	double result1 = p.getRoot1();
	double result2 = p.getRoot2();

	return 0;
}