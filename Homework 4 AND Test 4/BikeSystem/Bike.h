#pragma once
#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Bike
{
	friend class BikeSystem;
protected:
	string serial;
	bool occupied = false;
	int distance = 0;
	int x;
	int y;
	int comfort;
	//int cost_per_hour;

public:
	Bike():serial(""), x(0), y(0), comfort(0) {}
	Bike(const char *id, int location_x, int location_y, int comfort_rating):serial(id), x(location_x), y(location_y), comfort(comfort_rating) {}
	virtual ~Bike() {}
	virtual bool unlock();
	virtual int lock();
	int move_to(int destination_x, int destination_y);
	virtual int compute_cost();
};