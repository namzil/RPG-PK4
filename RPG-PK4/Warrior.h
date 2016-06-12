#ifndef WARRIOR_H
#define WARRIOR_H


#include "Player.h"
#include "SkillTreeWarrior.h"

class Warrior : public Player, public SkillTreeWarrior {
private:
	int maxRage;
	int currentRage;

public:
	Warrior(char*);
	~Warrior();
	void writeStatistic();
	void levelUp();
	void updateSkills();
	
	void castBasicAttack(Enemy&);
	void castHeroicStrike(Enemy&);
	void useSkill(char, Enemy&);
};


#endif