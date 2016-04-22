#ifndef SKILLTREE_H
#define SKILLTREE_H
//#include "Player.h"
#include <typeinfo>
#include <string>

using namespace std;

class SkillTree {
private:
	string skillName;
	bool canBeUsed;

public:
	SkillTree();
	~SkillTree();
	
	void unlockSkill(string);

//	int basicAttack(Player*);

	void heal();



};


#endif