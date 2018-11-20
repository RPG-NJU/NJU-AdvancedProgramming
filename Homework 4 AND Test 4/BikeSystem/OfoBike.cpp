#include "OfoBike.h"

bool OfoBike::unlock()
{
	if (!occupied)
	{
		occupied = true;
		cout << "unlock " << serial << endl;
		return true;
	}
	else
	{
		cout << "fail to unlock " << serial << endl;
		return false;
	}
}

int OfoBike::lock()
{
	if (occupied)
	{
		occupied = false;
		int cost = this->compute_cost();
		distance = 0;
		cout << "lock " << serial << endl;
		return cost;
	}
	else
	{
		cout << serial << " has been locked" << endl;
		return -1;
	}
}

int OfoBike::compute_cost()
{
	int time = distance / 21;
	distance % 21 == 0 ? time = time : time += 1;
	int cost = time * 2;
	return cost - 7 >= 0 ? cost - 7 : 0;
}

