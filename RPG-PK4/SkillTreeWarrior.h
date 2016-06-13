#ifndef SKILLTREEWARRIOR_H
#define SKILLTREEWARRIOR_H
#include "SkillTree.h"

class SkillTreeWarrior : public SkillTree
{
protected:
	Skill heroicStrike = Skill("Heroiczny cios", 10, 1);
	Skill bloodlust = Skill("Zadza krwi", 30, 3);

public:
	SkillTreeWarrior();
	~SkillTreeWarrior();

	void showSkills();
};


#endif