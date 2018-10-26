#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
T* merge(T* array_1, size_t size_1, T* array_2, size_t size_2)
{
	T *ret = new T[size_1 + size_2];
	int point(0);
	for (int i = 0, j = 0; i < size_1 || j < size_2;)
	{
		if (i >= size_1)
		{
			ret[point] = array_2[j];
			++j;
			++point;
		}
		else if (j >= size_2)
		{
			ret[point] = array_1[i];
			++i;
			++point;
		}
		else
		{
			if (array_1[i] < array_2[j])
			{
				ret[point] = array_1[i];
				++i;
				++point;
			}
			else
			{
				ret[point] = array_2[j];
				++j;
				++point;
			}
		}
	}
	return ret;
}