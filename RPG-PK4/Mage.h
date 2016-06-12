#ifndef MAGE_H
#define MAGE_H

#include "Player.h"
#include "SkillTreeMage.h"


class Mage : public Player, public SkillTreeMage {
private:
	int maxMana;
	int currentMana;

	//SkillTree* skills;

	//SkillTree* skills;

public:
	Mage(char*);
	~Mage();
	void writeStatistic();
	void levelUp();
	void updateSkills();
	void useSkill(char, Enemy&);
	void castBasicAtttack(Enemy&);
	void castHeal();
	void castFireBlast(Enemy&);

};



#endif

