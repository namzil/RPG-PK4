#ifndef SKILLTREERANGER_H
#define SKILLTREERANGER_H
#include "SkillTree.h"

class SkillTreeRanger : public SkillTree
{
protected:
	Skill headShot = Skill("Strzal w glowe", 20, 1);

public:
	SkillTreeRanger();
	~SkillTreeRanger();
	void showSkills();
};

#endif