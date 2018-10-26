#pragma once
#include <iostream>
#include <string>

//#define Iterator Interator
using std::string;
using std::cout;
using std::cin;
using std::endl;

template <typename T>
class Iterator
{
private:
	T *ptr;
public:
	Iterator() = default;
	Iterator(T *p):ptr(p){}
	~Iterator() {}
	Iterator operator+(const size_t x);
	Iterator operator-(const size_t x);
	Iterator& operator=(const Iterator x);
	bool operator==(const Iterator x);
	bool operator!=(const Iterator x);
	T& operator*();
	Iterator& operator++();
	Iterator& operator--();
	Iterator operator++(int);
	Iterator operator--(int);
	void Show();
};

template <typename T>
Iterator<T> Iterator<T>::operator+(const size_t x)
{
	ptr = ptr +x;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator-(const size_t x)
{
	ptr = ptr -x;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator x)
{
	ptr = x.ptr;
	return *this;
}

template <typename T>
bool Iterator<T>::operator==(const Iterator x)
{
	return (ptr == x.ptr);
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator x)
{
	return (ptr != x.ptr);
}

template <typename T>
T& Iterator<T>::operator*()
{
	return *ptr;
}

template <typename T>
Iterator<T>& Iterator<T>::operator++()
{
	ptr += 1;
	return *this;
}

template <typename T>
Iterator<T>& Iterator<T>::operator--()
{
	ptr -= 1;
	return *this;
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	Iterator x = *this;
	++*this;
	return x;
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	Iterator x = *this;
	--*this;
	return x;
}

template <typename T>
void Iterator<T>::Show()
{
	cout <<"ptr="<< ptr << endl;
}
