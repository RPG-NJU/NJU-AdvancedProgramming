#include "RecurveList.h"

ListNode* List::NewNode(const int item)
{
	return new ListNode(item);
}

void List::NewList(const int retvalue)
{
	while (1)
	{
		int input(0);
		cin >> input;
		if (input == retvalue)
			break;
		else
		{
			if (first == nullptr)
			{
				first = new ListNode(input);
				current = first;
				++tmp;
			}
			else
			{
				//此时已经有了头结点
				current->link = new ListNode(input);
				current = current->link;
				++tmp;
			}
		}
	}
	return;
}

void List::PrintList()
{
	ListNode *p = first;
	for (; p != nullptr; p = p->link)
	{
		cout << p->data << " ";
	}
	return;
}

int List::Max(ListNode* f)
{
	ListNode *p = first;
	int ret = -10000000;
	for (; p != nullptr; p = p->link)
	{
		ret = max(ret, p->data);
	}
	return ret;
}

int List::Num(ListNode* f)
{
	ListNode *p = first;
	int ret = 0;
	for (; p != nullptr; p = p->link)
	{
		++ret;
	}
	return ret;
}

float List::Avg(ListNode* f, int& n)
{
	ListNode *p = first;
	double ret = 0;
	///int n = 0;
	for (; p != nullptr; p = p->link)
	{
		//++n;
		ret += p->data;
	}
	return ret / n;
}
