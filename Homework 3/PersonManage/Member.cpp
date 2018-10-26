#include "Member.h"

Member::Member(int id, const char* name, int date, const char* department) :ID(id), name(name), date(date), department(department) {}

void Member::printInfo() const
{
	cout << ID << " " << name << " " << date << " " << department << endl;
	return;
}

