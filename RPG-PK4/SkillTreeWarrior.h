#ifndef SKILLTREEWARRIOR_H
#define SKILLTREEWARRIOR_H
#include "SkillTree.h"

class SkillTreeWarrior : public SkillTree
{
protected:
	Skill heroicStrike = Skill("Heroiczny cios", 10, 2);

public:
	SkillTreeWarrior();
	~SkillTreeWarrior();

	void showSkills();
};


#endif