#ifndef RANGER_H
#define RANGER_H


#include "Player.h"
#include "SkillTreeRanger.h"


class Ranger : public Player, public SkillTreeRanger {
private:
	int maxEnergy;
	int currentEnergy;

public:
	Ranger() {};
	Ranger(char*);
	~Ranger();
	void writeStatistic();
	void levelUp();
	void updateSkills();
	
	void castBasicAttack(Enemy&);
	void castHeadShot(Enemy&);
	void castAimedShot(Enemy&);
	void useSkill(char, Enemy&);
};



#endif