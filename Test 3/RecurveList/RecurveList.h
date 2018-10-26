#pragma once
#include <iostream> //定义在头文件"RecurveList.h"中
#include <algorithm>
using namespace std;
class List;
class ListNode 
{ //链表结点类
	friend class List;
private:
	int data; //结点数据
	ListNode *link; //结点指针
	ListNode(const int item) : data(item), link(nullptr) { } //构造函数
};
class List { //链表类
private:
	ListNode *first, *current;
	int tmp;//临时变量
	int Max(ListNode *f);
	int Num(ListNode *f);
	float Avg(ListNode *f, int& n);
public:
	List() : first(NULL), current(NULL), tmp(0) { } //构造函数
	~List() { } //析构函数
	ListNode* NewNode(const int item); //创建链表结点, 其值为 item
	void NewList(const int retvalue); //建立链表, 以输入 retvalue 结束
	void PrintList(); //输出链表所有结点数据
	int GetMax() { return Max(first); } //求链表所有数据的最大值
	int GetNum() { return Num(first); } //求链表中数据个数
	float GetAvg() { return Avg(first, tmp); } //求链表所有数据的平均值
};