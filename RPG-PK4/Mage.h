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
	Mage(string);
	~Mage();
	void writeStatistic();
};



#endif