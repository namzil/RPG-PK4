#include "SkillTreeWarrior.h"

SkillTreeWarrior::SkillTreeWarrior()
{
}

SkillTreeWarrior::~SkillTreeWarrior()
{
}

void SkillTreeWarrior::showSkills()
{
	SkillTree::showSkills();
	heroicStrike.isAvalible();
	bloodlust.isAvalible();
}
