#include <iostream>
#include <cstdlib>
#include <time.h>
#include <unistd.h>

#include "card.h"

using namespace std;

void Card::selfintro()
{
	cout<<"I'm a card";
}

Card::Card()
{
	id = rand() % CARD_TYPE_NUM;
}

Card::Card(int cardid)
{
	id = cardid;
}

Card::Card(Card& card)
{
	id = card.GetId();
	cout << "Setting card id using instance." << endl;
}

int Card::GetId()
{
	return id;
}
