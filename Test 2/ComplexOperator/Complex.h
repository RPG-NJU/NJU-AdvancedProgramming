#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using std::setprecision;

class Complex
{
private:
	double real;
	double unreal;
public:
	Complex();
	Complex(double x) :real(x), unreal(0) {}
	Complex(double x, double y) :real(x), unreal(y) {}
	friend istream& operator>>(istream &is, Complex &input);
	friend ostream& operator<<(ostream &os, Complex output);
	friend Complex operator+(const Complex &x, const Complex &y);
	friend Complex operator-(const Complex &x, const Complex &y);
	friend bool operator==(const Complex &x, const Complex &y);
	friend bool operator!=(const Complex &x, const Complex &y);
	Complex& operator+=(const Complex &x);
	Complex& operator-=(const Complex &x);
	Complex& operator++();//不需要传入参数，默认有参数
	Complex operator*(const Complex &x);
	Complex operator/(const Complex &x);
	~Complex(){}
	Complex& operator=(const Complex &x);
};