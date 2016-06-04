#ifndef SKILL_H
#define SKILL_H

#include <string>

using namespace std;

class Skill {
private:
	string skillName;
	bool canBeUsed;
	int cost;
	int levelRequired;

public:
	Skill(string, int, int); //Do poprawek
	~Skill();
	void loadSkills(); //do zrobienia

	string getSkillName();
	bool getCanBeUsed();
	int getCost();

	void setSkillName(string);
	void setCanBeUsed(bool);
	void setCost(int);
};


#endif