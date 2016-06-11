#ifndef MAGE_H
#define MAGE_H


#include "Player.h"
#include "SkillTree.h"


class Mage : public Player {
private:
	int maxMana;
	int currentMana;
	SkillTree* skills;

public:
	Mage(char*);
	~Mage();
	void writeStatistic();
	int getCurrentMana();
	int getMaxMana();
};



#endif