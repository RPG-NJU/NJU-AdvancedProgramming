#pragma once
#pragma once
#include "cards.h"

class Campus_Person
{
public:
	string get_campus_id();
	Bank_Card* get_b_card();
	Campus_Person(string campus_id, Bank_Card* b_card);
	~Campus_Person();
protected:
	string campus_id;
	Bank_Card* b_card;
};
class Student : public Campus_Person 
{
	friend class Teacher;
	Student_Card* s_card;
public:
	Student_Card* get_s_card();
	Student(string campus_id, Bank_Card* b_card, Student_Card* s_card);
	~Student();
	int bind_card(Bank_Card* b_card);
};
class Teacher : public Campus_Person {
	Teacher_Card* t_card;
	vector<Student*> stus;
public:
	Teacher_Card* get_t_card();  	vector<Student*>* get_students();
	Teacher(string campus_id, Bank_Card* b_card, Teacher_Card* t_card);
	~Teacher();
	int add_bind_card(Bank_Card* b_card);
	int delete_bind_card(Bank_Card* b_card);
	int add_student(Student* stu);
	int delete_student(Student* stu);

};
