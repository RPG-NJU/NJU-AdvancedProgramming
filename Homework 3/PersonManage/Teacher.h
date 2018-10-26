#pragma once
#include "Member.h"

class Teacher :public Member
{
private:
	string title;
public:
	Teacher() = default;
	Teacher(int id, const char *name, int date, const char *department, const char *title);
	~Teacher() {}
};