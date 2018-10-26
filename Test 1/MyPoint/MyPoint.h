#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

class MyPoint
{
private:
	int x;
	int y;
public:
	MyPoint();
	MyPoint(int x, int y);
	int getX() const;
	int getY() const;
	double distance(const MyPoint p);
	double distance(int x, int y);
};