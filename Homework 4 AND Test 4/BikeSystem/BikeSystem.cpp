#include "BikeSystem.h"
#include <iostream>
#include <cmath>
using namespace std;

int BikeSystem::search(const char *user_name, int start_x, int start_y, int acceptive_comfort_rating) const 
{
	bool have_find(false);
	int how_far(INT32_MAX);
	int how_comfort(-1);
	int ret(-1);
	Bike *this_one(nullptr);
	//请在此输入实现，请不要更改其余已有api
	for (int find(0); find < size; ++find)
	{
		if (!bikes[find]->occupied && bikes[find]->comfort >= acceptive_comfort_rating)
		{
			//此时是没有被占用的单车，并且是符合用户想要的舒适度的
			if (abs(bikes[find]->x - start_x) + abs(bikes[find]->y - start_y) <= how_far)
			{
				if (abs(bikes[find]->x - start_x) + abs(bikes[find]->y - start_y) < how_far)
				{
					how_far = abs(bikes[find]->x - start_x) + abs(bikes[find]->y - start_y);
					how_comfort = bikes[find]->comfort;
					this_one = bikes[find];
					ret = find;
					have_find = true;
				}
				else
				{
					//此时距离是相等的
					if (bikes[find]->comfort > how_comfort)
					{
						how_comfort = bikes[find]->comfort;
						this_one = bikes[find];
						ret = find;
						have_find = true;
					}
				}
			}		
		}
	}
	
	if (have_find)
	{
		cout << user_name << " selected " << this_one->serial << endl;

	}
	else
	{
		cout << user_name << " found no bikes available" << endl;
	}
	
	return ret;
}

BikeSystem::BikeSystem() {
	this->capability = INIT_CAP;
	this->bikes = new Bike*[this->capability];
	this->size = 0;
	this->incremental = this->capability / 2;
	for (int i = 0; i < this->capability; ++i) {
		this->bikes[i] = nullptr;
	}
}
BikeSystem::~BikeSystem() {
	release(this->bikes, this->size);
}
bool BikeSystem::unlock_bike(int bike_indicator) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL) {
		cerr << "fail to unlock with bike indicator " << bike_indicator << endl;
		return false;
	}
	return this->bikes[bike_indicator]->unlock();
}
int BikeSystem::ride_record(int bike_indicator, int destination_x, int destination_y) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL) {
		cerr << "fail to ride with bike indicator " << bike_indicator << endl;
		return 0;
	}
	return this->bikes[bike_indicator]->move_to(destination_x, destination_y);
}
int BikeSystem::lock_bike(int bike_indicator) {
	if (bike_indicator >= this->size || this->bikes[bike_indicator] == NULL) {
		cerr << "fail to lock with bike indicator " << bike_indicator << endl;
		return 0;
	}
	return this->bikes[bike_indicator]->lock();
}

void BikeSystem::add(Bike *bike) {
	if (this->size == this->capability) { // realloc
		cout << "realloc" << endl;
		this->capability += this->incremental;
		if (INIT_CAP / this->incremental < 8) {
			this->incremental /= 2;
			if (this->incremental < 1) this->incremental = 1;
		}
		Bike** new_bikes = new Bike*[this->capability];
		memcpy(new_bikes, this->bikes, this->size * sizeof(Bike*));
		for (int i = this->size; i < this->capability; ++i) {
			new_bikes[i] = nullptr;
		}
		delete[]this->bikes;
		this->bikes = new_bikes;
	}
	this->bikes[this->size] = bike;
	++this->size;
}
void BikeSystem::release(Bike **bike_list, int num) {
	if (bike_list == nullptr) {
		return;
	}
	for (int i = 0; i < num; ++i) {
		if (bike_list[i] != nullptr) {
			delete bike_list[i];
		}
	}
	delete[]bike_list;
	bike_list = nullptr;
}