#ifndef SKILL_H
#define SKILL_H

#include "curses.h"

#include <string>
#include <iostream>


using namespace std;

class Skill {
private:
	char* skillName;
	bool canBeUsed;
	int cost;
	int levelRequired;

public:
	Skill(char*, int, int); 
	~Skill();

	void isAvalible(); 

	char* getSkillName();
	bool getCanBeUsed();
	int getCost();
	int getLevelRequired();

	void setSkillName(char*);
	void setCanBeUsed(bool);
	void setCost(int);
	void setLevelRequired(int);
};


#endif