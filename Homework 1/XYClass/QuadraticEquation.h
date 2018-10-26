#pragma once
#include <iostream>
#include <cmath>

class QuadraticEquation
{
private:
	int a;
	int b;
	int c;
public:
	QuadraticEquation(int a, int b, int c);//构造函数，且a不会为0，于是就少了一种讨论情况
	int getA() const;
	int getB() const;
	int getC() const;
	int getDiscriminant();
	double getRoot1();
	double getRoot2();
};
