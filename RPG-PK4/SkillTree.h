#ifndef SKILLTREE_H
#define SKILLTREE_H
#include "Player.h"
#include "Skill.h"
#include <typeinfo>
#include <string>

using namespace std;

class SkillTree
{
protected:
	Skill basicAttack = Skill("1.Atak podstawowy", 0, 0);

public:
	SkillTree();
	~SkillTree();
	virtual void showSkills() = 0;
	Skill getBasicAttack();
	//void castBasicAttack(Enemy);
};

#endif