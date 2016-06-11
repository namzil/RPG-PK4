#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "Map.h"
#include "Game.h"
#define CONSOLE_KEY_QUIT 81

class Control
{
private:

public:
	void catchEvents(Map*, Player*);
	bool detectColision(int x, int y, Map*, Player*);
	void fight(Player*);
};


#endif

