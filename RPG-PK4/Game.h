#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Enemy.h"

enum state { GAME, FIGHT, END };

class Game
{
private:
	state gameState;


public:
	Game();
	~Game();
	void fight(Player*);//do zrobienia
};



#endif