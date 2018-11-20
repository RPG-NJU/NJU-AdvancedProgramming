#include "List.h"

int main()
{
	/*
	List<int> l;
	List<int>::iterator it = l.begin();
	it = l.insert(it, 0);
	it = l.insert(it, 1);
	it = l.insert(it, 2);
	++it;
	it = l.erase(it);
	for (it = l.begin(); it != l.end(); it++) 
	{
		cout << *it << endl;
	}
	*/

	List<char> l;
	l.insert(l.end(), 'a');
	l.insert(l.end(), 'b');
	l.insert(l.end(), 'c');
	l.insert(l.end(), 'd');
	List<char>::iterator it = l.erase(l.begin());
	it = l.erase(it);
	for (; it != l.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}