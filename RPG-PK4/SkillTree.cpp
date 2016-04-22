#include "SkillTree.h"

SkillTree::SkillTree()
{
	skillName = "Niedostepne";
	canBeUsed = 0;
}

SkillTree::~SkillTree()
{
}

void SkillTree::unlockSkill(string name)
{
	skillName = name;
	canBeUsed = 1;
}
