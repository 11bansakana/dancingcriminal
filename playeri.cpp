#include <iostream>
#include <vector>

#include "playeri.h"
#include "playero.h"

using namespace std;


int Playeri::Draw(Card card)
{
	Card *newcard;
	if(cards.size() == 4)
	{
		cout << "Max size reached." << endl;
		return cards.size();
	}
	else
	{
		newcard = new Card();
		if(!newcard)
		{
			cout << "Not enough memory to new instance." << endl;
		}
		cards.push_back(newcard);
	}

}

int Playeri::Draw(Card *card)
{
	if(card)
	{
		cards.push_back(card);
	}
	cout << "Now has " << cards.size() << " cards." << endl;
	return 0;
}

Card *Playeri::Play()
{
	Card *c = NULL;
	if(!cards.empty())
	{
		c = cards.back();
		cards.pop_back();
	}
	return c;
}

int Playeri::GetCardNum()
{
	return cards.size();
}

vector<int> Playeri::GetAllCards()
{
	vector<int> allcardsidx;
	return allcardsidx;
}

Card *Playeri::Get(int idx)
{
	Card *card;
	vector<Card *>::iterator i = cards.begin();
	if(idx >= cards.size())
		return NULL;
	card = cards[idx];
	cards.erase(i + idx);
	return card;
}

bool Playeri::HaveAlibi()
{
	for(int i = 0 ; i < cards.size() ; i++)
	{
		if(cards[i]->GetId() == CARDTYPE_ALIBI)
			return true;
	}
	return false;
}

int Playeri::Choice(int c)
{
	return 1;
}
