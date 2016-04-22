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

string SkillTree::skillsList(int number, int level)
{
	string spell;
	switch (number)
	{
		case 1:{
			if (level )
			return spell;
		}
		case 2: {

		}
		case 3: {

		}
	}
	//if ()
	return spell;
}


/*int SkillTree::basicAttack(Player* player)
{
	int damage;

	damage = player->getDamage()*player->getStrenght()*0.2;

	return damage;
}*/
