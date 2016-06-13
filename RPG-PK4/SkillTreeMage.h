#ifndef SKILLTREEMAGE_H
#define SKILLTREEMAGE_H
#include "SkillTree.h"

class SkillTreeMage : public SkillTree
{
protected:
	Skill fireBlast = Skill("3.Ognisty pocisk", 20, 1);
	Skill heal = Skill("2.Leczenie", 10, 0);
	Skill pyroblast = Skill("4.Pyroblast", 50, 3);

public:
	SkillTreeMage();
	~SkillTreeMage();
	void showSkills();
};

#endif