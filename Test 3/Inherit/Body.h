#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ios;
using std::setprecision;

#define PI 3.14

class Body
{
protected:
	double height;
public:
	Body() = default;
	Body(double height);
	void printHeight();
	virtual ~Body() {}
};