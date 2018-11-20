#include "cards.h"

string Card::get_card_id()
{
	return card_id;
}

Card::Card(string card_id, int account_balance) : card_id(card_id), account_balance(account_balance) {}

Card::~Card()
{

}

int Card::get_accunt_balance()
{
	return account_balance;
}


Bank_Card::Bank_Card(string card_id, int account_balance) :Card(card_id, account_balance) {}

Bank_Card::~Bank_Card()
{

}

int Bank_Card::recharge(int num)
{
	account_balance += num;
	return 0;
}

int Bank_Card::consume(int num)
{
	if (num > account_balance)
	{
		return -1;
	}
	else
	{
		account_balance -= num;
		return 0;
	}
}

Bank_Card* Student_Card::get_b_card()
{
	return b_card;
}

Student_Card::Student_Card(string card_id, int account_balance, Bank_Card* b_card) :Card(card_id, account_balance), b_card(b_card) {}

Student_Card::~Student_Card()
{

}

int Student_Card::consume(int num)
{
	if (num > account_balance)
	{
		return -1;
	}
	else
	{
		account_balance -= num;
		return 0;
	}
}

int Student_Card::recharge(Bank_Card* b_card, int num)
{
	if (b_card != this->b_card)
		return -1;
	if (b_card->get_accunt_balance() < num)
		return -1;
	else
	{
		account_balance += num;
		b_card->consume(num);
		return 0;
	}
}



double Teacher_Card::get_discount()
{
	return discount;
}

vector<Bank_Card*>* Teacher_Card::get_b_cards()
{
	return &b_cards;
}

Teacher_Card::Teacher_Card(string card_id, int account_balance, double discount, Bank_Card* b_card) :Card(card_id, account_balance), discount(discount)
{
	b_cards.push_back(b_card);
}

int Teacher_Card::consume(int num)
{
	if (num * discount > account_balance)
		return -1;
	else
	{
		account_balance -= num * discount;
		return 0;
	}
}

int Teacher_Card::recharge(Bank_Card* b_card, int num)
{
	bool flag = false;
	Bank_Card *y = nullptr;
	for (auto x : b_cards)
	{
		if (x == b_card)
		{
			flag = true;
			y = x;
			break;
		}
	}
	if (!flag)
	{
		return -1;
	}

	else
	{
		account_balance += num;
		y->consume(num);
		return 0;
	}
}

Teacher_Card::~Teacher_Card()
{

}















