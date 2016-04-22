#ifndef SKILLTREE_H
#define SKILLTREE_H
#include "Player.h"
#include <typeinfo>
#include <string>

using namespace std;

class Player;

class SkillTree {
private:
	string skillName;
	bool canBeUsed;

public:
	SkillTree();
	~SkillTree();
	
	void unlockSkill(string);

	string skillsList(int, int); // do zrobienia

	//int basicAttack(Player*);

	void heal();



};


#endif