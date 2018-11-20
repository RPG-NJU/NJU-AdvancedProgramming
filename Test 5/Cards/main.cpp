#include "cards.h"
#include "persons.h"


int main()
{
	/*
		创建一个学生
	*/
	Bank_Card* s_b_card = new Bank_Card("s_b1", 100);
	Student_Card* s_card = new Student_Card("s_s1", 0, s_b_card);
	Student* s = new Student("s_1", s_b_card, s_card);

	/*
		创建一个老师
	*/
	Bank_Card* t_b_card = new Bank_Card("t_b1", 100);
	Teacher_Card* t_card = new Teacher_Card("t_s1", 0, 0.9, t_b_card);
	Teacher* t = new Teacher("t_1", t_b_card, t_card);

	/*
		测试银行卡功能
	*/
	s_b_card->consume(10);
	//cout << s_b_card->get_accunt_balance() << endl;
	if (s_b_card->get_accunt_balance() != 90) cout << "wrong1" << endl;
	s_b_card->recharge(10);
	if (s_b_card->get_accunt_balance() != 100) cout << "wrong2" << endl;

	/*
		测试学生卡功能
	*/
	s_card->recharge(s_b_card, 10);
	cout << s_b_card->get_accunt_balance() << " " << s_card->get_accunt_balance() << endl;
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 10)
		cout << "wrong3" << endl;
	s_card->consume(10);
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 0)
		cout << "wrong4" << endl;
	//新建一张未绑定的卡，此处应该充值失败 
	Bank_Card* temp1 = new Bank_Card("temp1", 100);  	
	s_card->recharge(temp1, 10);  	
	if (s_card->get_accunt_balance() != 0 || temp1->get_accunt_balance() != 100) 
		cout << "wrong5" << endl;

	/*
		测试老师卡功能
	*/
	t_card->recharge(t_b_card, 10);  	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 10) cout << "wrong6" << endl;  	t_card->consume(10);  	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 1) cout
		<< "wrong7" << endl;
	//使用学生卡充值，此处应该充值失败 
	t_card->recharge(s_b_card, 10);  	if (t_b_card->get_accunt_balance() != 90 || t_card->get_accunt_balance() != 1 || s_b_card->get_accunt_balance() != 90) cout << "wrong8" << endl;

	/*
		测试学生绑定功能
	*/
	s->bind_card(temp1);
	s_card->recharge(s_b_card, 10);
	cout << s_b_card->get_accunt_balance() << " " << s_card->get_accunt_balance() << endl;
	if (s_b_card->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 0)
		cout << "wrong9" << endl;  	
	s_card->recharge(temp1, 10);
	if (temp1->get_accunt_balance() != 90 || s_card->get_accunt_balance() != 10) cout
		<< "wrong10" << endl;

	/*
		测试老师绑定功能
	*/
	t->add_student(s);  	t->add_bind_card(s->get_b_card());  	t_card->recharge(s_b_card, 10);
	if (s_b_card->get_accunt_balance() != 80 || t_card->get_accunt_balance() != 11) cout << "wrong11" << endl;
	//解除银行卡的绑定之后不能进行充值 
	t->delete_bind_card(s->get_b_card());  	t_card->recharge(s_b_card, 10);  	if (s_b_card->get_accunt_balance() != 80 || t_card->get_accunt_balance() != 11) cout << "wrong11" << endl;
	//不是老师学生的卡不能进行绑定 
	Bank_Card* test1 = new Bank_Card("test1", 100);  	if (t->add_bind_card(test1) != -1) cout << "wrong12" << endl;
	//测试删除学生 
	t->delete_student(s);  	if (t->add_bind_card(s->get_b_card()) != -1) cout << "wrong13" << endl;

	return 0;

}