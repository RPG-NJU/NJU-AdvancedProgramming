#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

using namespace std;


class Shell
{
private:
	string now_dir;
	string home;
public:
	Shell(string homedir = "/") :now_dir(homedir)
	{
		if (now_dir[now_dir.length() - 1] != '/') now_dir.push_back('/');
		while (now_dir.find("//", 0) != string::npos)
		{
			int kill_place = now_dir.find("//", 0);//找到这个字符的位置
			now_dir = now_dir.erase(kill_place, 1);//将其删除
		}
		if (now_dir[0] != '/' && now_dir[0] != '~')
			now_dir = "/" + now_dir;
		home = now_dir;
	}
	~Shell() {}
	void cd(string path = "");
	void pwd();
	void distance(string path);
};

void Shell::pwd()
{
	cout << now_dir << endl;
	return;
}

void Shell::distance(string path)
{
	//计算路径可能是最麻烦的了，我就是有点啰嗦，你管我
	//可能需要先建立一个虚拟的路径
	//Shell now = 
	Shell where_goto(home);
	where_goto.now_dir = now_dir;
	where_goto.cd(path);//将goto的位置建立成为一个完整的路径

	
	/*cout << "=======" << endl;
	this->pwd();
	where_goto.pwd();
	cout << "=======" << endl;*/
	
	//int x(0);//作为开始寻找/的位置
	//while()//认为需要找到相同的路径过程，直到不相同为止
	int i(0);
	for (; i < now_dir.length() && i < where_goto.now_dir.length(); ++i)
	{
		if (now_dir[i] != where_goto.now_dir[i])
			break;
	}

	int count1(0);
	for (int x(i); x < now_dir.length(); ++x)
	{
		if (now_dir[x] == '/')
			++count1;
	}

	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count1;
	}
	//这时候的count是一个最坏情况的执行
	/*
	//===================================================================================
	i = 0;
	Shell copy(home);
	int count2(1);
	for (; i < copy.now_dir.length() && i < where_goto.now_dir.length(); ++i)
	{
		if (copy.now_dir[i] != where_goto.now_dir[i])
			break;
	}

	for (int x(i); x < copy.now_dir.length(); ++x)
	{
		if (copy.now_dir[x] == '/')
			++count2;
	}

	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count2;
	}
	//===================================================================================
	i = 0;
	int count3(0);
	for (int y(i); y < where_goto.now_dir.length(); ++y)
	{
		if (where_goto.now_dir[y] == '/')
			++count3;
	}

	if (count2 < count1)
		count1 = count2;
	if (count3 < count1)
		count1 = count3;
	*/
	cout << count1 << endl;

	return;
}

void Shell::cd(string path)
{
	string x;

	while (now_dir.find("//", 0) != string::npos)
	{
		int kill_place = now_dir.find("//", 0);//找到这个字符的位置
		now_dir = now_dir.erase(kill_place, 1);//将其删除
	}

	if (path.length() == 0)
	{
		now_dir = home;
		return;
	}
	/*
	for (int i(0); i < path.length(); ++i)
	{
		//x.push_back(path[i]);
		//if (i == path.length() - 1)//此时已经是最后一个位置了

	}
	*/

	else if (path[0] == '/')//此时从根目录开始延展
	{
		///*
		if (path.length()>1)
		{
			if (path[1] == '~')
				now_dir = home + path.erase(0, 3);
			else
				now_dir = path;
		}
		else
		//*/
			now_dir = path;
	}
	else if (path[0] == '~')//此时从home目录开始延展
	{
		now_dir = home + path.erase(0, 2);//删除从零开始的一个字符，也就是删除头字符
	}
	else
	{
		now_dir += path;
	}
	now_dir += "/";
	while (now_dir.find("//", 0) != string::npos)
	{
		int kill_place = now_dir.find("//", 0);//找到这个字符的位置
		now_dir = now_dir.erase(kill_place, 1);//将其删除
	}	
	//然后需要解析整个语句？将不必要的东西去掉
	//先想去掉./，这个是无意义的一个语句
	while (now_dir.find("/./", 0) != string::npos)
	{
		int kill_place = now_dir.find("/./", 0);//找到这个字符的位置
		now_dir = now_dir.erase(kill_place, 2);//将其删除
	}

	//然后是想要解析../这个字符串
	while (now_dir.find("/../", 0) != string::npos)
	{
		//cout <<"->"<< now_dir << endl;
		int x = now_dir.find("/../", 0);
		/*if (x == 0)
		{
			now_dir = now_dir.erase(0, 3);
			break;
		}*/
		now_dir = now_dir.erase(x, 3);//把这个位置删除
		//但是还需要删除这个位置之前的一个目录位置，因为是上级目录的含义
		if (x != 0)
		{
			int y = now_dir.rfind('/', x - 1);//因为x的位置仍然是一个/，所以要向前寻找
			//cout << y <<" "<<x - y<< endl;
			now_dir = now_dir.erase(y, x - y);//将这个已经被越过的目录删除
		}
	}
	while (now_dir.length() > 1 && now_dir[now_dir.length() - 1] == '/' && now_dir[now_dir.length() - 2] == '/')
		now_dir.pop_back();

	//if (now_dir.length() == 0)
		//now_dir = "/";

	return;
}

