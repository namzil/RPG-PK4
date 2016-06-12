#include "SkillTree.h"

SkillTree::SkillTree()
{
}

SkillTree::~SkillTree()
{
}


void SkillTree::showSkills()
{
	cout << "Dostepne umiejetnosci:\n";
	basicAttack.isAvalible();
}

Skill SkillTree::getBasicAttack()
{
	return basicAttack;
}