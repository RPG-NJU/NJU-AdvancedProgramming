#include "Complex.h"

int main()
{
	Complex x(1);
	Complex y(3, 4);
	Complex z;
	z = x + y;
	cout << z;
	cout << x - y;
	cout << x * y;
	cout << x / y;
	return 0;
}