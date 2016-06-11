#ifndef RANGER_H
#define RANGER_H


#include "Player.h"
#include "SkillTree.h"


class Ranger : public Player {
private:
	int maxEnergy;
	int currentEnergy;


public:
	Ranger(char*);
	~Ranger();
	void writeStatistic();
};



#endif