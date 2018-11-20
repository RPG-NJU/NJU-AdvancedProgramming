#pragma once
#include "Bike.h"
class OfoBike : public Bike
{
public:
	OfoBike(const char *id, int location_x, int location_y, int comfort_rating) : Bike(id, location_x, location_y, comfort_rating) {}
	bool unlock() override;
	int lock() override;
	int compute_cost() override;
};