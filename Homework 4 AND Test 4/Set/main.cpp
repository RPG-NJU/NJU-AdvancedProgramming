#include "Set.h"


int main()
{
	
	int elements[] = { -1, 2, 0, 3, -5, 3 };
	int length = sizeof(elements) / sizeof(int);
	Set set1(elements, length);
	set1.add(3);
	std::cout << set1 << endl;
	std::cout << set1.size() << endl;
	std::cout << set1.contains(5) << endl;
	std::cout << set1 << endl;
	set1.add(6);
	std::cout << set1 << endl;
	std::cout << set1.erase(0) << endl;
	std::cout << set1 << endl;
	std::cout << set1.erase(1) << endl;
	std::cout << set1 << endl;
	

	/*int a[] = { -2,-1,0,1,2 };
	int b[] = { 0,1,2 };
	Set set1(a, 5);
	Set set2(b, 3);
	Set set3;
	std::cout << set1 + set2 << endl;
	std::cout << set1 - set2 << endl;
	std::cout << (set1 | set2) << endl;
	std::cout << (set1&set2) << endl;
	set1 += set2;
	std::cout << set1 << endl;
	set1 -= set2;
	std::cout << set1 << endl;
	std::cout << "============";
	std::cout << (set1 == set2) << endl;
	std::cout << (set1 != set2) << endl;
	std::cout << (set1 > set2) << endl;
	std::cout << (set1 >= set2) << endl;
	std::cout << (set1 < set2) << endl;
	std::cout << (set1 <= set2) << endl;
	std::cout << (set1 > set3) << endl;*/
	return 0;
}