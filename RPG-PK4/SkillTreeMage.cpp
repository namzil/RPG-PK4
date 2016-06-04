#include "SkillTreeMage.h"

SkillTreeMage::SkillTreeMage()
{
}

SkillTreeMage::~SkillTreeMage()
{
}

void SkillTreeMage::showSkills()
{
	SkillTree::showSkills();
	heal.isAvalible();
	fireBlast.isAvalible();
}
