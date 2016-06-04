#ifndef SKILLTREEMAGE_H
#define SKILLTREEMAGE_H
#include "SkillTree.h"

class SkillTreeMage : public SkillTree
{
protected:
	Skill fireBlast = Skill("Ognisty pocisk", 20, 1);
	Skill heal = Skill("Leczenie", 10, 0);

public:
	SkillTreeMage();
	~SkillTreeMage();
	void showSkills();
};

#endif