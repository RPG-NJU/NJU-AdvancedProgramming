#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	stackNode *p = top;
	for (; p != nullptr; p = top)
	{
		top = top->next;
		delete p;
	}
}

void Stack::push(char data)
{
	stackNode *p = new stackNode;
	p->data = data;
	p->next = top;
	top = p;
	return;
}

char Stack::pop()
{
	if (top == nullptr)
		return '\0';
	else
	{
		stackNode *p = top;
		top = top->next;
		char res = p->data;
		delete p;
		return res;
	}
}

char Stack::stackTop()
{
	if (top == nullptr)
		return '\0';
	else
	{
		return top->data;
	}
}

bool Stack::isEmpty()
{
	if (top == nullptr)
		return true;
	else
		return false;
}

void Stack::show()
{
	stackNode *p = top;
	for (;p != nullptr; p = p->next)
	{
		cout << p->data << endl;
	}
	return;
}


