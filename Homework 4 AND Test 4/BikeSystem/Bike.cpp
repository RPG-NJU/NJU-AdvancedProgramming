#include "Bike.h"

bool Bike::unlock()
{
	if (!occupied)
	{
		occupied = true;
		return true;
	}
	else
		return false;
}

int Bike::lock()
{
	if (occupied)
	{
		occupied = false;
		distance = 0;
		return 0;//这里没有给出Bike需要的价格
	}
	else
		return -1;
}

int Bike::move_to(int destination_x, int destination_y)
{
	cout << "from "<<x<<","<<y<<" to "<<destination_x<<","<<destination_y << endl;
	distance += abs(x - destination_x) + abs(y - destination_y);
	x = destination_x; y = destination_y;
	return distance;
}

int Bike::compute_cost()
{
	return 0;
}


