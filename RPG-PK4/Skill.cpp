#include "Skill.h"


//kostruktor
Skill::Skill(char* n, int c, int l)
{
	skillName = n;
	canBeUsed = 0;
	cost = c;
	levelRequired = l;
}

Skill::~Skill()
{
}

void Skill::isAvalible()
{
	if (canBeUsed)
		//cout << skillName << "\n";
		printw("%s\n",skillName);
}


char* Skill::getSkillName()
{
	return skillName;
}

bool Skill::getCanBeUsed()
{
	return canBeUsed;
}

int Skill::getCost()
{
	return cost;
}

int Skill::getLevelRequired()
{
	return levelRequired;
}

void Skill::setSkillName(char* s)
{
	skillName = s;
}

void Skill::setCanBeUsed(bool c)
{
	canBeUsed = c;
}

void Skill::setCost(int c)
{
	cost = c;
}

void Skill::setLevelRequired(int l)
{
	levelRequired = l;
}


