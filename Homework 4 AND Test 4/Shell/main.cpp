#include "Shell.h"

int main() {
	/*
	string homedir = "/home/user/Documents";
	Shell *s = new Shell(homedir);
	s->pwd();
	s->cd("/");
	s->cd("~/user/name/..");
	s->pwd();
	s->cd("/usr/local/inclue/");
	s->pwd();
	s->distance("./usr/local/inclue");
	*/

	/*
	string homedir = ".../home/user////Documents";
	Shell *s = new Shell(homedir);
	s->pwd();
	s->cd("~/");
	s->pwd();
	s->cd("/user/name/...");
	s->pwd();
	s->cd("/usr/local/inclue//.");
	s->pwd();
	s->cd("~");
	s->pwd();
	s->distance("~/usr/local////inclue///");
	s->distance("../");
	return 0;
	*/

	/*
	Shell *s = new Shell();
	s->cd("/~/");
	s->pwd();
	s->distance("./Hello/World/Bash");
	s->distance("/local/user/name");
	delete s;
	*/
	
	/*
	Shell *s = new Shell("shit");
	s->pwd();
	s->cd("~/user/name/..");
	s->pwd();
	s->cd("/usr/local/bash");
	s->cd("././../.../../hello/./");
	s->pwd();
	s->cd("hello/./hello");
	s->pwd();
	*/
	//return 0;

	/*
	Shell test("grp/howtodo");
	//Shell test;
	test.pwd();
	test.cd();
	test.pwd();
	test.distance("../../../howtodo/../../../../../howtodo");
	test.distance("../../../../cg/../../../");
	//test.cd("../../bb/../../../cg/././../");
	test.pwd();
	//test.cd("~/./././././././././././../../../../");
	test.pwd();
	//test.cd("./././././././././././../../../../../../../../../../");
	test.pwd();
	test.cd("~/../../../../../../fuck/../../");
	test.pwd();
	*/
	cout << "请输入一个地址作为home：";
	string home;
	cin >> home;
	Shell test(home);
	string input;
	string data;
	do
	{
		cout << "请输入一个指令空格之后输入路径：（路径为空输入0）";
		cin >> input >> data;
		if (data == "0")
			data.clear();
		if (input == "cd")
			test.cd(data);
		else if (input == "pwd")
			test.pwd();
		else if (input == "distance")
			test.distance(data);
		else
			cout << "这不是一个合适的指令" << endl;		
	} while (input != "q");
	return 0;
}