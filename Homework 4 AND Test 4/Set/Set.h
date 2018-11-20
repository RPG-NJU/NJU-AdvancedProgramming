#pragma once
#include <iostream>
#include <cstdlib>
#include <cstring>
//#include <string>

using std::istream;
using std::ostream;
using std::endl;


//new与delete操作的重载以及相关的简述放在了Set.cpp文件的末尾段============================================================



class Set
{
private:
	int *data;
	int max_length;
	int real_length;
public:
	Set();
	Set(const Set &set);
	Set(int elements[], int length);
	~Set();
	void add(int element);
	bool erase(int element);
	bool contains(int element) const;
	int size() const { return real_length; }
	Set& operator=(const Set &x);
	friend ostream& operator<<(ostream &os, Set set);
	friend Set operator+(const Set &lset, const Set &rset);
	Set& operator+=(const Set &rset);
	friend Set operator-(const Set &lset, const Set &rset);
	Set& operator-=(const Set &rset);
	friend Set operator&(const Set &lset, const Set &rset);
	friend Set operator|(const Set &lset, const Set &rset);
	friend bool operator==(const Set &lset, const Set &rset);
	friend bool operator!=(const Set &lset, const Set &rset);
	friend bool operator>(const Set &lset, const Set &rset);
	friend bool operator<(const Set &lset, const Set &rset);
	friend bool operator>=(const Set &lset, const Set &rset);
	friend bool operator<=(const Set &lset, const Set &rset);
	static void *operator new(size_t size);
	static void *operator new(size_t size, void *p);
	static void operator delete(void *p, size_t size);
};