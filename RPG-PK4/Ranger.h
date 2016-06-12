#ifndef RANGER_H
#define RANGER_H


#include "Player.h"
#include "SkillTreeRanger.h"


class Ranger : public Player, public SkillTreeRanger {
private:
	int maxEnergy;
	int currentEnergy;


public:
	Ranger(char*);
	~Ranger();
	void writeStatistic();
	void levelUp();
	void updateSkills();

};



#endif