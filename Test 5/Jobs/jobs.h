#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::queue;
using std::iterator;
using std::sort;


struct Job
{
	int id;//唯一指定ID
	int enter_time;//进入的时间
	int duration;//Job持续的时间
	int priority;//Job的优先级
	//可以自己增加实现方法
};

class JobSchedual
{
public:
	JobSchedual(Job js[], int length);
	~JobSchedual() {}


	void FCFS();//先来先执行
	void RoundRobin(int time_slice);
	void PrioritySchedual();

	friend bool time_compare(Job &x, Job &y);

private:
	vector<Job> list;

	
	void time_sort();
	void power_sort();

	int now_time;
};

JobSchedual::JobSchedual(Job js[], int length)
{
	for (int i(0); i < length; ++i)
	{
		list.push_back(js[i]);
	}
	now_time = 0;
}

void JobSchedual::FCFS()
{
	//std::sort(list.begin(), list.end(), &JobSchedual::time_compare);//根据时间进行排序
	time_sort();

	for (auto x : list)
	{
		if (x.enter_time > now_time)
			now_time = x.enter_time;
		//时间修正

		now_time += x.duration;
		cout << x.id << " " << now_time << endl;
	}
}
bool time_compare(Job &x, Job &y)
{
	return x.enter_time < y.enter_time;
}


void JobSchedual::RoundRobin(int time_slice)
{
	std::sort(list.begin(), list.end(), time_compare);//进行时间排序
	//time_sort();
	while (!list.empty())
	{
		if (now_time < list.begin()->enter_time)
			now_time = list.begin()->enter_time;
		//时间修正
		//cout << "->" << now_time << endl;
		if (list.begin()->duration <= time_slice)
		{
			now_time += list.begin()->duration;
			cout << list.begin()->id << " " << now_time << endl;
			list.erase(list.begin());
		}

		else
		{
			now_time += time_slice;
			list.begin()->duration -= time_slice;
			list.begin()->enter_time = now_time;

			Job mid = *list.begin();
			list.erase(list.begin());
			list.push_back(mid);

			time_sort();
		}
	}
	return;
}


void JobSchedual::time_sort()
{
	for (int i(0); i < list.size() - 1; ++i)
	{
		for (int j(0); j < list.size() - 1; ++j)
		{
			if (list[j].enter_time > list[j+1].enter_time)
			{
				Job mid = list[j];
				list[j] = list[j + 1];
				list[j + 1] = mid;
			}
		}
	}
	return;
}

void JobSchedual::power_sort()
{
	for (int i(0); i < list.size() - 1; ++i)
	{
		for (int j(0); j < list.size() - 1; ++j)
		{
			if (list[j].enter_time > list[j+1].enter_time)
			{
				Job mid = list[j];
				list[j] = list[j + 1];
				list[j + 1] = mid;
			}
			else if (list[j].enter_time == list[j + 1].enter_time)
			{
				if (list[j].priority < list[j + 1].priority)
				{
					Job mid = list[j];
					list[j] = list[j + 1];
					list[j + 1] = mid;
				}

			}
		}
	}
	return;
}

void JobSchedual::PrioritySchedual()
{
	power_sort();

	while (!list.empty())
	{
		//cout << "?" << endl;
		if (now_time < list.begin()->enter_time)
			now_time = list.begin()->enter_time;

		//时间的修正

		if (list.size() > 1)
		{
			/*cout << "===================" << endl;
			for (auto x: list)
			{
				cout << x.id << "-" << x.enter_time << "-" << x.duration << "-" << x.priority << endl;
			}*/
			if (list[0].enter_time + list[0].duration > list[1].enter_time)
			{

				if (list[0].priority < list[1].priority)
				{
					list[0].duration = list[0].duration - (list[1].enter_time - list[0].enter_time);
					list[0].enter_time = list[1].enter_time;
					
					now_time = list[0].enter_time;
					power_sort();
				}
				else
				{
					//list[1].enter_time += list[0].duration;
					++list[1].enter_time;
					power_sort();
				}
			}

			else
			{
				now_time = now_time + list[0].duration;
				cout << list[0].id << " " << now_time << endl;
				list.erase(list.begin());
				power_sort();
			}
		}

		else
		{
			now_time = now_time + list[0].duration;
			cout << list[0].id << " " << now_time << endl;
			list.erase(list.begin());
		}
	}

	return;
}


