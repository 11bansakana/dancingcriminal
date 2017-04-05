#ifndef __CARD_H__
#define __CARD_H__

#include <time.h>
#include <unistd.h>
#include <stdlib.h>

/*Card id definition.*/
enum cardid {
	DETECTIVE = 0,
	CRIMINAL,
	FIRSTDISCOVER,
	WITNESS,
	ALIBI,
	INFOTRADE,
	DEAL,
	RUMOR,
	NOBODY,
	DOG,

};

#define CARDTYPE_DETECTIVE 0
#define CARDTYPE_CRIMINAL 1
#define CARDTYPE_FIRSTFINDER 2
#define CARDTYPE_WITNESS 3
#define CARDTYPE_ALIBI 4
#define CARDTYPE_INFOTRADE 5
#define CARDTYPE_DEAL 6
#define CARDTYPE_RUMOR 7
#define CARDTYPE_NOBODY 8
#define CARDTYPE_DOG 9

#define CARD_TYPE_NUM 10





class Card{
	public:
		Card();
		Card(int cardid);
		Card(Card& card);
		int GetId();
		void selfintro();
		static void SetSeed()
		{
			srand(time(NULL));
		}
	private:
		char cardname[48];
		char carddesc[256];
		int id;
};
#endif
