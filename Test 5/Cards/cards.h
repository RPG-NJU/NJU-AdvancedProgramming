#pragma once
#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
class Card
{
public:
	string get_card_id();

	Card(string card_id, int account_balance);
	~Card();
	int get_accunt_balance();

protected:

	string card_id;
	int account_balance;
};
class Bank_Card : public Card
{
public:
	Bank_Card(string card_id, int account_balance);
	~Bank_Card();
	int recharge(int num);
	int consume(int num);
};
class Student_Card : public Card
{
	friend class Student;
	friend class Teacher;
	Bank_Card* b_card;
public:
	Bank_Card* get_b_card();
	Student_Card(string card_id, int account_balance, Bank_Card* b_card);
	~Student_Card();
	int consume(int num);
	int recharge(Bank_Card* b_card, int num);

};

class Teacher_Card : public Card
{
	friend class Teacher;
	double discount;
	vector<Bank_Card*> b_cards;
public:
	double get_discount();
	vector<Bank_Card*>* get_b_cards();
	Teacher_Card(string card_id, int account_balance, double discount, Bank_Card* b_card);
	~Teacher_Card();
	int consume(int num);
	int recharge(Bank_Card* b_card, int num);

};