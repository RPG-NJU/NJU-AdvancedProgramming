#pragma once
#include <iostream>

using namespace std;

template <typename T>
void sort(T *array, unsigned length)
{
	for (int time = 0; time < length - 1; ++time)//循环次数限制
	{
		for (int i = 0; i < length - 1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				T mid = array[i]; array[i] = array[i + 1]; array[i + 1] = mid;
			}
		}
	}
	return;
}
