#include "Complex.h"
#include <iostream>

Complex::Complex()
{
	real = 0;
	unreal = 0;
}

istream& operator>>(istream &is, Complex &input)
{
	is >> input.real >> input.unreal;
	if (!is)//检查流是否正确
		input = Complex();
	return is;
}

ostream& operator<<(ostream& os, Complex output)
{
	/*
	if (output.real == 0 && output.unreal == 0)
		os << "0";
	else if (output.real == 0)
		os << output.unreal << "i";
	else if (output.unreal == 0)
		os << output.real;
	else
	{
		if (output.unreal > 0)
			os << output.real << "+" << output.unreal << "i";
		else
			os << output.real << output.unreal << "i";
	}
	*/
	os << output.real << setprecision(2) << " " << output.unreal << setprecision(2);
	return os;
}

Complex operator+(const Complex &x, const Complex &y)
{
	Complex ret(x.real + y.real, x.unreal + y.unreal);
	return ret;
}

bool operator==(const Complex &x, const Complex &y)
{
	return (x.real == y.real && x.unreal == y.unreal);
}

bool operator!=(const Complex &x, const Complex &y)
{
	return !(x == y);
}

Complex& Complex::operator+=(const Complex& x)
{
	real += x.real;
	unreal += x.unreal;
	return *this;
}

Complex& Complex::operator-=(const Complex& x)
{
	real -= x.real;
	unreal -= x.unreal;
	return *this;
}

Complex& Complex::operator++()
{
	//其实没有什么意义，就不做了
	return *this;
}

Complex& Complex::operator*(const Complex& x)
{
	Complex ret;
	ret.real = real * x.real - unreal * x.unreal;
	ret.unreal = unreal * x.real + real * x.unreal;
	return ret;
}

Complex& Complex::operator/(const Complex& x)
{
	Complex ret;
	ret.real = (real * x.real - unreal * (-x.unreal)) / (x.real * x.real + x.unreal * x.unreal);
	ret.unreal = (real * (-x.unreal) + unreal * x.real) / (x.real * x.real + x.unreal * x.unreal);
	return ret;
}

