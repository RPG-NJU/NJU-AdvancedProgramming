#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct stackNode
{
	char data;
	stackNode *next;
};

class Stack
{
private:
	stackNode *top;//’ª∂•÷∏’Î
public:
	Stack();
	~Stack();
	void push(char data);
	char pop();
	char stackTop();
	bool isEmpty();
	void show();
};
