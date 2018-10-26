#include "RecurveList.h"

int main()
{
	List test;
	int finished;
	cout << "输入建表结束标志数据 ：";
	cin >> finished; //输入建表结束标志数据
	cout << "Input your data: " << endl; //提示
	test.NewList(finished); //建立链表
	cout << "The List is : " << endl;
	test.PrintList(); //打印链表
	cout << endl;
	cout << "The Max is : " << test.GetMax() << endl;
	cout << "The Num is : " << test.GetNum() << endl;
	cout << "The Ave is : " << test.GetAvg() << endl;
	return 0;
}