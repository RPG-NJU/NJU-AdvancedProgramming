#include "Body.h"
#include "Cylinder.h"
#include "ThreePrism.h"
#include "Cone.h"
int main()
{
	Cylinder test1(4.0, 5.0);
	test1.getArea();
	test1.getVolume();
	test1.printHeight();
	Cylinder test2(4.0, 3.75);
	test2.getArea();
	test2.getVolume();
	test2.printHeight();
	return 0;
}