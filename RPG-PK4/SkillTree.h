#ifndef SKILLTREE_H
#define SKILLTREE_H
//#include "Player.h"
#include <typeinfo>
#include <string>

using namespace std;

class Player;

class SkillTree {
private:
	string skillName;
	bool canBeUsed;
	//SkillTree asd = new SkillTree[3];

public:
	SkillTree();
	~SkillTree();
	
	void unlockSkill(string);
	string getSkillName();

	string skillsList(int, int); // do zrobienia

	//int basicAttack(Player*);

	void heal();



};


#endif