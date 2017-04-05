#ifndef __PLAYERI_H__
#define __PLAYERI_H__

#include <array>
#include <vector>

#include "card.h"

using namespace std;
/*
   PlayerI
   server side inner player abstract class.
 */
class Playeri{
	public:
		Card *Play();
		int Draw(Card card);	
		int Draw(Card* card);
		/*Get Player's card count.*/
		int GetCardNum();
		/*Get all cards*/
		vector<int> GetAllCards();
		Card *Get(int);

		int Choice(int c);
	protected:
		bool HaveAlibi();
	private:
		vector<Card *> cards;
		//Vector<Card> Cards;
};
#endif
