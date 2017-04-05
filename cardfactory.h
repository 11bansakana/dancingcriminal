#ifndef __CARDFACTORY_H__
#define __CARDFACTORY_H__

#include "game.h"

class CardFactory
{
	public:
		int Load(Game *game);
		CardFactory();
	private:
		/*Change to vector later.*/
		Card cards[16];

};


#endif
