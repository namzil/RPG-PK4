#ifndef WARRIOR_H
#define WARRIOR_H


#include "Player.h"

class Warrior : public Player {
private:
	int maxRage;
	int actuallRage;

public:
	Warrior(string);
	~Warrior();
	void writeStatistic();
};


#endif