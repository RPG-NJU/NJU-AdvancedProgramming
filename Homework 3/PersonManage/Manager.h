#pragma once
#include "Member.h"
//using namespace std;

class Manager
{
private:
	std::vector<class Member*> list;
public:
	void add(Member *member);
	void sortById();
	void sortByDate();
	void printSearch(const int id) const;
	void printAll() const;
};