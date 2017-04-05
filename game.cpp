



#include <iostream>


#include "game.h"
#include "playeri.h"


using namespace std;
int Game::LeftPlayerIdx(int idx, int size)
{
	return idx == 0?idx + size - 1: idx - 1;
}
int Game::InsertCard(Card card)
{
	Card *newcard = new Card(card);
	if(newcard == NULL)
	{
		cout << "Create new card instance failed." << endl;
	}
	pile.push_front(newcard);
}

int Game::RegisterPlayer(Playero player)
{
	Playeri *newplayeri = new Playeri();
	if(newplayeri != NULL)
	{
		players.push_back(newplayeri);
		cout << __FUNCTION__ << ":" << players.size() << " players have joined the game." << endl;
	}
	return players.size();
}


int Game::Deal()
{
	int nextplayer = 0;
	list<Card *>::iterator pos = pile.begin();
	cout << "Dealing " << pile.size() << "cards to " << players.size() << "players." <<endl;
	for(int i = 0 ; i < pile.size() ; i++)
	{
		cout << "assigning card " << i << " to player " << nextplayer << endl;
		players[nextplayer]->Draw(*pos);
		pos++;
		nextplayer++;
		nextplayer = nextplayer % players.size();
	}
	return 0;
}

Game::Game()
{
	cout << "New game initialized." << endl;
}

void Game::Begin()
{
	int playedcards = 0;

	int turn = 0;
	int idx;

	vector<int> allcards;
	Card *pcard = NULL;


	if(players.size() == 0)	
	{
		cout << "Players number invalid.(" << players.size() << ")" << endl;
		return;
	}
	/*4 should be replace with macro definition.*/
	std::vector<Playeri *>::iterator i = players.begin();
	while(playedcards < players.size() * 4)
	{
		pcard = players[turn]->Play();
		if(pcard != NULL)
		{
			switch(pcard->GetId())
			{
				case CARDTYPE_DETECTIVE:
					cout << "Detective, choose a player:" << endl;
					/*lower mark is max number of players - 1*/
					idx = players[turn]->Choice(players.size() - 1);
					cout << "Player " << turn << " choose " << idx << endl;
					break;
				case CARDTYPE_CRIMINAL:
					cout << "Criminal." << endl;
					if(players[turn]->GetCardNum() == 0)
					{
						cout << "Player " << turn << " wins." << endl;
					}
					else
					{
						cout << "Player " << turn << " lose." << endl;
					}
					/*Calculate score*/
					break;
				case CARDTYPE_FIRSTFINDER:
					cout << "First finder, nothing happened." << endl;
					break;
				case CARDTYPE_WITNESS:
					idx = players[turn]->Choice(players.size() - 1);
					while(idx == turn || players[idx]->GetCardNum() == 0)
					{
						cout << "Player is yourself or have no card. Rechoice!" << endl;
						idx = players[turn]->Choice(players.size() - 1);
					}
					allcards = players[idx]->GetAllCards(); 
					//send them to player[turn] to see.  function not designed.
					break;	
				case CARDTYPE_ALIBI:
					cout << "Alibi, nothing happened." << endl;
					break;
				case CARDTYPE_INFOTRADE:
					break;
				case CARDTYPE_DEAL:
					break;
				case CARDTYPE_RUMOR:
					break;
				case CARDTYPE_NOBODY:
					cout << "Alibi, nothing happened." << endl;
					break;
				case CARDTYPE_DOG:
					break;
				default:
					break;
			}
			delete pcard;
			playedcards++;
		}
		turn++;
		turn = turn % players.size();
	}
	cout << "game finished." << endl;
}
