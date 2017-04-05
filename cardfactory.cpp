#include <assert.h>
#include <time.h>


#include "cardfactory.h"

CardFactory::CardFactory()
{


}

int CardFactory::Load(Game *game)
{
	assert(game);
	for(int i = 0 ; i < 16 ; i++)
	{
		game->InsertCard(cards[i]);
	}
	return 0;
}
