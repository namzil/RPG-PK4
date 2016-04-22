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

/*int SkillTree::basicAttack(Player* player)
{
	int damage;

	damage = player->getDamage()*player->getStrenght()*0.2;

	return damage;
}*/
