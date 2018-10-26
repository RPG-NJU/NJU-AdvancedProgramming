#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;

template <typename T>
struct List
{
	T data;
	List *before;
	List *next;
};

template <typename T>
class Queue
{
private:
	List<T> *head;//队列的数据结构
	List<T> *tail;
	size_t length;
public:
	Queue();
	~Queue();
	void push(T e);
	T pop();
	T back();
	T front();
	bool isEmpty();
	size_t size();
	void show();
};

template <typename T>
Queue<T>::Queue()
{
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
Queue<T>::~Queue()
{
	for (;tail != head;)
	{
		List<T> *p = tail;
		tail = tail->before;
		delete p;
	}
	delete head;
	head = tail = nullptr;
}

template <typename T>
void Queue<T>::push(T e)
{
	if (head == nullptr)
	{
		List<T> *p = new List<T>{ e,nullptr,nullptr };
		head = p;
		tail = p;
		++length;
	}
	else
	{
		List<T> *p = new List<T>{ e,tail,nullptr };
		tail->next = p;
		tail = tail->next;
		++length;
	}
	return;
}

template <typename T>
T Queue<T>::pop()
{
	if (head == tail)
		tail = nullptr;
	T ret = head->data;
	List<T> *p = head;
	head = head->next;
	delete p;
	--length;
	return ret;
}

template <typename T>
T Queue<T>::back()
{
	return tail->data;
}

template <typename T>
T Queue<T>::front()
{
	return head->data;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template <typename T>
size_t Queue<T>::size()
{
	return length;
}

template <typename T>
void Queue<T>::show()
{
	if (length != 0)
	{
		List<T> *p = head;
		for (;p != tail; p = p->next)
		{
			cout << p->data << " ";
		}
		cout << p->data << endl;
	}
	return;
}
