#include "SkillTree.h"

SkillTree::SkillTree()
{
}

SkillTree::~SkillTree()
{
}


void SkillTree::showSkills()
{
	printw("Dostepne umiejetnosci:\n");
	basicAttack.isAvalible();
}

Skill SkillTree::getBasicAttack()
{
	return basicAttack;
}