#include "persons.h"

Campus_Person::Campus_Person(string campus_id, Bank_Card* b_card) : campus_id(campus_id), b_card(b_card) {}
Campus_Person::~Campus_Person()
{

}

string Campus_Person::get_campus_id()
{
	return campus_id;
}

Bank_Card* Campus_Person::get_b_card()
{
	return b_card;
}


Student::Student(string campus_id, Bank_Card* b_card, Student_Card* s_card) :Campus_Person(campus_id, b_card), s_card(s_card) {}

Student::~Student()
{

}

int Student::bind_card(Bank_Card* b_card)
{
	this->s_card->b_card = b_card;
	return 0;
}

Student_Card* Student::get_s_card()
{
	return s_card;
}


Teacher_Card* Teacher::get_t_card()
{
	return t_card;
}

vector<Student*>* Teacher::get_students()
{
	return &stus;
}

Teacher::Teacher(string campus_id, Bank_Card* b_card, Teacher_Card* t_card) :Campus_Person(campus_id, b_card), t_card(t_card) {}

Teacher::~Teacher()
{

}

int Teacher::add_bind_card(Bank_Card* b_card)
{
	bool flag = false;
	for (auto x : stus)
	{
		if (x->get_s_card()->get_b_card() == b_card)
		{
			flag = true;
			break;
		}
	}
	for (auto x : t_card->b_cards)
	{
		if (b_card == x)
			flag = true;
	}
	if (flag)
	{
		t_card->b_cards.push_back(b_card);
		return 0;
	}
	else
		return -1;
}

int Teacher::delete_bind_card(Bank_Card* b_card)
{
	for (auto x = t_card->b_cards.begin(); x != t_card->b_cards.end(); x++)
	{
		if (*x == b_card)
		{
			t_card->b_cards.erase(x);
			return 0;
		}
	}
	return -1;
}

int Teacher::add_student(Student* stu)
{
	stus.push_back(stu);
	return 0;
}

int Teacher::delete_student(Student* stu)
{
	for (auto x = stus.begin(); x != stus.end(); x++)
	{
		if (*x == stu)
		{
			stus.erase(x);
			return 0;
		}
	}
	return -1;
}










