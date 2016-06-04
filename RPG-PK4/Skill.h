#ifndef SKILL_H
#define SKILL_H

#include <string>
#include <iostream>

using namespace std;

class Skill {
private:
	string skillName;
	bool canBeUsed;
	int cost;
	int levelRequired;

public:
	Skill(string, int, int); 
	~Skill();

	void isAvalible(); 

	string getSkillName();
	bool getCanBeUsed();
	int getCost();
	int getLevelRequired();

	void setSkillName(string);
	void setCanBeUsed(bool);
	void setCost(int);
	void setLevelRequired(int);
};


#endif