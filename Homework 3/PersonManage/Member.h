#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Manager.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

class Member
{
protected:
	int ID;
	string name;
	int date;
	string department;
public:
	Member() = default;
	Member(int id, const char *name, int date, const char *department);
	void printInfo() const;
	virtual ~Member() {}
	friend class Manager;
};