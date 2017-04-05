#ifndef __GAME_H__
#define __GAME_H__

#include <list>
#include <vector>
#include "card.h"
#include "playeri.h"
#include "playero.h"

using namespace std;

class Game
{
	public:
		int RegisterPlayer(Playero player);
		Game();
		int InsertCard(Card card);
		int Deal();
		//***Main Loop of the Game***
		void Begin();  
	protected:
		int LeftPlayerIdx(int idx, int size);
	private:
		//Card CardPool Vector type
		list<Card *> pile;
		vector<Playeri *> players;
};

#endif
