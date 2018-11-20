#ifndef BIKESYSTEM_H
#define BIKESYSTEM_H

#include <iostream>
#include <cstdlib>
#include "Bike.h"
#include <cstring>

#define INIT_CAP 1000
using namespace std;

class BikeSystem
{
private:
	Bike** bikes; // Bike*类型的数组，数组每项都是指向单车类型的指针
	int size; // 单车数量，即查找操作在bikes数组下标为[0, size-1]范围内查询
	int capability; // 系统最大支持的单车数量
	int incremental; // 每次动态分配的单车（内存）增量
public:
	/**
	 * @brief 从单车列表中查找满足条件的、最近的、当前未被占用的单车
	 * 		查找条件：1. 单车没被占用
	 *              2. 单车的舒适度不小于acceptive_comfort_rating
	 * 		成功找到，则输出"名字 selected 单车id"；找不到，则输出"名字 found no bikes available"
	 * @param user_name 执行查找单车操作的用户标识（名字）
	 * @param start_x 用户所在位置横坐标x
	 * @param start_y 用户所在位置纵坐标y
	 * @param acceptive_comfort_rating 可以接受的最小单车舒适度
	 * @return 返回满足查找条件的单车在bikes数组中的下标：
	 * 				1. 如果有多辆满足查找条件的单车，则返回距离最近的
	 * 				2. 如果距离最近的单车有多辆，则返回舒适度最高的
	 *              3. 如果上述条件都相同，则返回在bikes数组中下标最小的
	 *              4. 没找到返回 -1
	 */
	int search(const char* user_name, int start_x, int start_y, int acceptive_comfort_rating) const;

	/**
	 * @brief 解锁单车操作，调用Bike的unlock方法
	 * @param bike_indicator 待解锁单车在单车数组中的下标
	 * @return 解锁成功返回true，解锁失败返回false
	 */
	bool unlock_bike(int bike_indicator);

	/**
	 * @brief 骑行记录，调用Bike的move_to方法
	 * @param bike_indicator 待解锁单车在单车数组中的下标
	 * @param destination_x 终点横坐标
	 * @param destination_y 终点纵坐标
	 * @return 当前骑行累积里程数
	 */
	int ride_record(int bike_indicator, int destination_x, int destination_y);

	/**
	 * @brief 骑行结束，给单车重新上锁，调用Bike的lock方法，此时单车变为空闲状态，累积里程数清零
	 * @param bike_indicator 待解锁单车在单车数组中的下标
	 * @return 上锁成功则根据累积里程数计算累积费用并返回，上锁失败返回0
	 */
	int lock_bike(int bike_indicator);

	/**
	 * @brief 默认构造函数，初始化单车列表
	 */
	BikeSystem();

	/**
	 * @brief 往管理系统中添加单车
	 * @param bike
	 */
	void add(Bike* bike);

	/**
	 * @brief 释放bike_list数组空间
	 * @param bike_list Bike*类型的数组
	 */
	void release(Bike* bike_list[], int num);

	/**
	 * @brief 析构函数，释放空间
	 */
	~BikeSystem();
};

#endif // BIKESYSTEM_H
