#include "HelloBike.h"

bool HelloBike::unlock()
{
	
	if (!occupied)
	{
		occupied = true;
		cout << "unlock " << serial << " " << lock_string << endl;
		return true;
	}
	else
	{
		cout<< "fail to unlock " << serial << " " << lock_string << endl;
		return false;
	}
	
	//return false;
}

int HelloBike::compute_cost()
{
	int time = distance / 25;
	distance % 25 == 0 ? time = time : time += 1;
	int cost = time * 2;
	return cost - 5 >= 0 ? cost - 5 : 0;
}

int HelloBike::lock()
{
	
	if (occupied)
	{
		occupied = false;
		int cost = this->compute_cost();
		distance = 0;
		cout << "lock " << serial << " " << lock_string << endl;
		return cost;
	}
	else
	{
		cout << serial << " " << lock_string << " has been locked" << endl;
		return -1;
	}
	
	//return 0;
}
