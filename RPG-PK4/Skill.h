#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill {
private:
	string skillName;
	bool canBeUsed;
	int cost;
	bool isHealingSpell;

public:
	Skill(); //Do poprawek
	~Skill();

};


#endif