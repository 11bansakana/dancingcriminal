#include <iostream>
#include <time.h>
#include <cstdlib>

#include "game.h"
#include "card.h"
#include "cardfactory.h"

using namespace std;

int main(int ac, char **av)
{
	Playero playero[4];
	Game newgame;
	Card::SetSeed();
	CardFactory factory;

	factory.Load(&newgame);
	for(int i = 0 ; i < 4 ; i++)
	{
		newgame.RegisterPlayer(playero[i]);
	}
	newgame.Deal();
	newgame.Begin();
}

