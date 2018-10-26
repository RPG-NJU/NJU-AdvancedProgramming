#include "Manager.h"

void Manager::add(Member *member)
{
	list.push_back(member);
	return;
}

void Manager::sortById()
{
	for (int i(0); i < list.size(); ++i)
	{
		for (int j(0); j < list.size() - 1; ++j)
		{
			if (list[j]->ID > list[j + 1]->ID)
			{
				Member *mid = list[j]; list[j] = list[j + 1]; list[j + 1] = mid;
			}
		}
	}
	return;
}

void Manager::sortByDate()
{
	for (int i(0); i < list.size(); ++i)
	{
		for (int j(0); j < list.size() - 1; ++j)
		{
			if ((list[j]->date > list[j + 1]->date)
				||(list[j]->date == list[j + 1]->date && list[j]->ID > list[j+1]->ID))
			{
				Member *mid = list[j]; list[j] = list[j + 1]; list[j + 1] = mid;
			}
		}
	}
	return;
}


void Manager::printAll() const
{
	for (int i(0); i < list.size(); ++i)
		list[i]->printInfo();
	return;
}

void Manager::printSearch(const int id) const
{
	for (int i(0); i < list.size(); ++i)
	{
		if (list[i]->ID == id)
		{
			list[i]->printInfo();
			break;
		}
	}
	return;
}

