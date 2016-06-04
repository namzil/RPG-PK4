#ifndef MAGE_H
#define MAGE_H


#include "Player.h"
#include "SkillTreeMage.h"


class Mage : public Player, public SkillTreeMage {
private:
	int maxMana;
	int currentMana;

	//SkillTree* skills;

public:
	Mage(string);
	~Mage();
	void writeStatistic();
	void levelUp();
	void updateSkills();

};



#endif