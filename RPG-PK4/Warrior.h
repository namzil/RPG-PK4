#ifndef WARRIOR_H
#define WARRIOR_H


#include "Player.h"
#include "SkillTreeWarrior.h"

class Warrior : public Player, public SkillTreeWarrior {
private:
	int maxRage;
	int currentRage;

public:
	Warrior(string);
	~Warrior();
	void writeStatistic();
	void levelUp();
	void updateSkills();
};


#endif