#ifndef WARRIOR_H
#define WARRIOR_H


#include "Player.h"
#include "SkillTree.h"

class Warrior : public Player {
private:
	int maxRage;
	int currentRage;

public:
	Warrior(char*);
	~Warrior();
	void writeStatistic();
};


#endif