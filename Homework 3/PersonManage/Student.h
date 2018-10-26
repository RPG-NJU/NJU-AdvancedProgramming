#pragma once
#include "Member.h"

class Student :public Member
{
private:
	string Major;
public:
	Student() = default;
	Student(int id, const char *name, int date, const char *department, const char *major);
	~Student() {}
};