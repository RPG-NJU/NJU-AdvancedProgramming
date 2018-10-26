#include "Vector.h"

int main()
{
	Vector<int> v(10); //最多可容纳 10 个元素
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Vector<int>::iterator it = v.begin();
	for (it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	v.insert(v.begin(), 0);
	v.erase(v.end() - 1);
	for (size_t i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}