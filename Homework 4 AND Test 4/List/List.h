#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


template <typename T>
struct _List_node
{
	_List_node<T> *prev;
	_List_node<T> *next;
	T data;
};

template <typename T>
struct _List_iterator
{
	_List_node<T> *_p_node;
	_List_iterator(_List_node<T> *x):_p_node(x) {}
	~_List_iterator() {}
	bool operator==(_List_iterator y) const;
	bool operator!=(_List_iterator y) const;
	_List_iterator& operator++();
	_List_iterator operator++(int);
	_List_iterator& operator--();
	_List_iterator operator--(int);
	T& operator*();
};

template <typename T>
class List
{
public:
	typedef _List_node<T> link_type;
	typedef _List_iterator<T> iterator;
private:
	link_type *node;
public:
	List();
	~List();
	bool empty();
	iterator begin();
	iterator end();

	iterator insert(iterator it, T e);
	iterator erase(iterator it);
};



template <typename T>
bool _List_iterator<T>::operator==(_List_iterator y) const
{
	return _p_node == y._p_node;
}

template <typename T>
bool _List_iterator<T>::operator!=(_List_iterator y) const
{
	return !(*this == y);
}

template <typename T>
_List_iterator<T>& _List_iterator<T>::operator++()
{
	this->_p_node = this->_p_node->next;
	return *this;
}

template <typename T>
_List_iterator<T> _List_iterator<T>::operator++(int)
{
	_List_iterator ret = *this;
	++(*this);
	return ret;
}

template <typename T>
_List_iterator<T>& _List_iterator<T>::operator--()
{
	this->_p_node = this->_p_node->prev;
	return *this;
}

template <typename T>
_List_iterator<T> _List_iterator<T>::operator--(int)
{
	_List_iterator ret = *this;
	--(*this);
	return ret;
}

template <typename T>
T& _List_iterator<T>::operator*()
{
	return _p_node->data;
}

template <typename T>
List<T>::List()
{
	node = new _List_node<T>;
	node->prev = node;
	node->next = node;
	node->data = *(new T);
}

template <typename T>
bool List<T>::empty()
{
	return node->next == node;
}

template <typename T>
typename List<T>::iterator List<T>::begin()
{
	return *(new iterator(node->next));
}

template <typename T>
typename List<T>::iterator List<T>::end()
{
	return *(new iterator(node->prev->next));
}

template <typename T>
typename List<T>::iterator List<T>::insert(iterator it, T e)
{
	link_type *add = new link_type;
	add->data = e;
	/*
	for (iterator i(this->begin()); i != this->end(); ++i)
	{
		if (i == it)
			break;
	}
	*/
	add->next = it._p_node;
	add->prev = it._p_node->prev;
	add->prev->next = add;
	it._p_node->prev = add;
	return *(new iterator(add));
}

template <typename T>
typename List<T>::iterator List<T>::erase(iterator it)
{
	it._p_node->prev->next = it._p_node->next;
	it._p_node->next->prev = it._p_node->prev;
	iterator ret = it._p_node->next;
	delete it._p_node;
	return ret;
}

template <typename T>
List<T>::~List()
{
	iterator x = this->begin();
	iterator y = this->end();
	for (iterator i = x; i != y; ++i)
		delete i._p_node;
}
