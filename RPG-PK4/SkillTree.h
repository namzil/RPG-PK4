#ifndef SKILLTREE_H
#define SKILLTREE_H
#include "Player.h"
#include "Skill.h"
#include <typeinfo>
#include <string>

using namespace std;

class SkillTree
{
private:
	Skill basicAttack;
	
public:
	SkillTree();
	~SkillTree();
	virtual void showSkills() = 0;
};

#endif