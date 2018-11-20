#pragma once
#include "Bike.h"
class HelloBike : public Bike
{
private:
	string lock_string;
public:
	HelloBike(const char *id, const char *elock_id, int location_x, int location_y, int comfort_rating) : Bike(id, location_x, location_y, comfort_rating) , lock_string(elock_id){}
	bool unlock() override;
	int lock() override;
	int compute_cost() override;
};