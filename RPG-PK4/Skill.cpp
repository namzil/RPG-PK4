#include "Skill.h"


//kostruktor
Skill::Skill(string n, int c, int l)
{
	skillName = n;
	canBeUsed = 0;
	cost = c;
	levelRequired = l;
}

Skill::~Skill()
{
}

//chyba do usuniecia
void Skill::loadSkills()
{

}

string Skill::getSkillName()
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

void Skill::setSkillName(string s)
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
