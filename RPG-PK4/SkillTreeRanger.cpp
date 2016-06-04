#include "SkillTreeRanger.h"

SkillTreeRanger::SkillTreeRanger()
{
}

SkillTreeRanger::~SkillTreeRanger()
{
}

void SkillTreeRanger::showSkills()
{
	SkillTree::showSkills();
	headShot.isAvalible();
}
