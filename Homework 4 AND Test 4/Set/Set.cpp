#include "Set.h"

Set::Set()
{
	data = new int[10];
	max_length = 10;
	real_length = 0;
}

Set::Set(const Set& set)
{
	max_length = set.max_length;
	real_length = set.real_length;
	data = new int[max_length];
	for (int i(0); i < max_length; ++i)
	{
		data[i] = set.data[i];
	}
}

Set& Set::operator=(const Set& x)
{
	max_length = x.max_length;
	real_length = x.real_length;
	delete data;
	data = new int[max_length];
	for (int i(0); i < max_length; ++i)
	{
		data[i] = x.data[i];
	}
	return *this;
}


Set::Set(int elements[], int length)
{
	max_length = length;
	data = new int[max_length];

	int i(0);
	for (int j(0); j < max_length; ++j)
	{
		int find(0);
		for (; find < i; ++find)
		{
			if (data[find] == elements[j])
				break;
		}
		if (find == i)
		{
			data[i] = elements[j];
			++i;
		}
	}
	real_length = i;
}

Set::~Set()
{
	delete data;
}

void Set::add(int element)
{
	if (real_length == max_length)
	{
		//此时需要扩展集合，否则就装不下了
		int *old = data;
		data = new int[2 * max_length];
		max_length *= 2;
		for (int i(0); i < max_length; ++i)
			data[i] = old[i];

	}
	//无论是需不需要扩展，后续的操作应该是一致的
	if (!this->contains(element))
	{
		data[real_length] = element;
		++real_length;
	}
	return;
}

bool Set::erase(int element)
{
	int find(0);
	for (; find < real_length; ++find)
	{
		if (data[find] == element)
			break;
	}
	if (find == real_length)
		return false;
	else
	{
		int i(find);
		data[find] = 0;
		for (; i < real_length - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		--real_length;
		return true;
	}
}

bool Set::contains(int element) const
{
	int find(0);
	for (; find < real_length; ++find)
	{
		if (data[find] == element)
			break;
	}
	return !(find == real_length);
}

ostream& operator<<(ostream& os, Set set)
{
	if (set.real_length == 0)
		os << "Empty" /*<< endl*/;
	else
	{
		for (int i(0); i <set.real_length - 1; ++i)
		{
			for (int j(0); j < set.real_length - 1; ++j)
			{
				if (set.data[j] > set.data[j + 1])
				{
					int mid = set.data[j]; set.data[j] = set.data[j + 1]; set.data[j + 1] = mid;
				}
			}
		}
		for (int i(0); i < set.real_length; ++i)
			os << set.data[i] << " ";
		//os << endl;
	}
	return os;
}

Set operator+(const Set& lset, const Set& rset)
{
	Set ret(lset);
	for (int i(0); i < rset.real_length; ++i)
	{
		if (!ret.contains(rset.data[i]))
			ret.add(rset.data[i]);
	}
	return ret;
}

Set& Set::operator+=(const Set& rset)
{
	*this = *this + rset;
	return *this;
}

Set operator-(const Set& lset, const Set& rset)
{
	Set ret;
	for (int i(0); i < lset.real_length; ++i)
	{
		if (!rset.contains(lset.data[i]))
			ret.add(lset.data[i]);
	}
	return ret;
}

Set& Set::operator-=(const Set& rset)
{
	*this = *this - rset;
	return *this;
}


Set operator&(const Set& lset, const Set& rset)
{
	Set ret;
	for (int i(0); i < lset.real_length; ++i)
	{
		if (rset.contains(lset.data[i]))
			ret.add(lset.data[i]);
	}
	return ret;
}

Set operator|(const Set& lset, const Set& rset)
{
	return lset + rset;
}

bool operator==(const Set& lset, const Set& rset)
{
	if (lset.real_length != rset.real_length)
		return false;
	else
	{
		int i(0);
		for (; i < lset.real_length; ++i)
		{
			if (!rset.contains(lset.data[i]))
				break;
		}
		return i == lset.real_length;
	}
}

bool operator!=(const Set& lset, const Set& rset)
{
	return !(lset == rset);
}

bool operator>(const Set& lset, const Set& rset)
{
	if (lset.real_length <= rset.real_length)
		return false;
	else
	{
		int i(0);
		for (; i < rset.real_length; ++i)
		{
			if (!lset.contains(rset.data[i]))
				break;
		}
		return i == rset.real_length;
	}
}

bool operator<(const Set& lset, const Set& rset)
{
	return rset > lset;
}

bool operator<=(const Set& lset, const Set& rset)
{
	return (lset < rset) || (lset == rset);
}

bool operator>=(const Set& lset, const Set& rset)
{
	return (lset > rset) || (lset == rset);
}

//下面是new与delete的操作以及我的相应简述===================================================================================================

void* Set::operator new(size_t size)
{
	void *p = malloc(size);//调用系统堆空间分配的操作，这里的size会自动计算，为Set类所占用的空间，不需要通过调用传递
	memset(p, 0, size);//将空间中全部初始化为0，为自定义的初始化形式
	return p;
}

void* Set::operator new(size_t size, void* p)
{
	return p;//第二个参数在调用的时候通过 new(p)类名()的形式进行使用，意义是将新的类的数据存放在p指针所指的地址，而非系统自己指定的地址
}

//在调用重载的new函数的时候，所使用的类的构造函数形式和以往的new形式一致，即new(p)类名(参数)的形式进行调用即可

void Set::operator delete(void* p, size_t size)
{
	free(p);//与new对应，进行空间的归还
}

/*
 * 另外，还有更加复杂以及自主的重载new和delete操作符的形式。
 * 其原因是因为计算机系统对于堆区空间的管理并不是非常的“节约”和高效。
 * 所以我们可以通过自主的定义来书写new操作符和delete操作符来管理空间。
 * 
 * 整体思想是申请NUM个该类对象所需要的空间（NUM的大小由编写者自己决定，而非系统）。
 * 然后通过链表的形式进行管理，在创建之初，整块空间都是连续可用的。
 * 然后通过一个链表的头，决定在new的时候采用的地址，在这个地址上创建了类之后，将这个地址的指针标记为不可以使用的空间。
 * 之后的new操作就不会再访问已经构造了类对象的空间。
 * 直到重载的delete被调用的时候，将所指向的指针的空间归还到可以使用的空间中，标记为可以被使用的，就可以再次被new操作进行初始化。
 * 经过了多次的new和delete操作之后，可以使用的空间可能就不再连续，而是断断续续的形态。
 * 
 * 同样的，如果一个NUM*sizeof(类)的空间不够大，可以再创建一个等大的空间，将他们进行连接，成为一个从访问方式上看的整体，而实际存储可能是不连续的。
 * 
 * 
 */
