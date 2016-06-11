#ifndef MAGE_H
#define MAGE_H

#include "Enemy.h"
#include "Player.h"
#include "SkillTree.h"


class Mage : public Player {
private:
	int maxMana;
	int currentMana;

	//SkillTree* skills;

public:
	Mage(char*);
	~Mage();
	void writeStatistic();

	void castBasicAttack(Enemy);
	void useSkill(Enemy, Skill);
};



#endif

