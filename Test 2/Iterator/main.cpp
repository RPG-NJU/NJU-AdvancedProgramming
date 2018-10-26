#include "Iterator.h"
#include <complex.h>

int main()
{
	int int_array[4] = { 1 ,2 ,3 ,4 };
	Iterator<int> i_begin(int_array);
	i_begin.Show();
	Iterator<int> i_end(int_array + 4);
	i_end.Show();
	Iterator<int> i = i_begin;
	for (; i != i_end; i++) 
	{
		i.Show();
		i_end.Show();
		cout << *i << endl;
		cout << "?" << endl;
	}
	i.Show();
}
