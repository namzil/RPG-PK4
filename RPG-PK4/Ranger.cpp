#include "Ranger.h"

//kostruktor
Ranger::Ranger(char* n) : Player(n)
{
	proffesion = ranger;
	maxHealth = 300;
	currentHealth = 300;
	maxEnergy = 150;
	currentEnergy = 150;
	agility = 20;
	strenght = 15;
	intellect = 15;
	updatePlayer();
}

Ranger::~Ranger()
{
}

//wypisywanie statystyk
void Ranger::writeStatistic()
{
	Player::writeStatistic();
	cout << "Energia: " << currentEnergy << "\\" << maxEnergy << "\n";
	showSkills();
}

void Ranger::levelUp()
{
	Player::levelUp();
	maxEnergy += maxEnergy*0.1;
	currentEnergy = maxEnergy;
}

void Ranger::updateSkills()
{
	if (level >= basicAttack.getLevelRequired())
		basicAttack.setCanBeUsed(1);
	if (level >= headShot.getLevelRequired())
		headShot.setCanBeUsed(1);
}

void Ranger::useSkill(char spell, Enemy & enemy)
{
	switch (spell)
	{
	case '1': {
		castBasicAttack(enemy);
		break;
	}
	case '2': {
		castHeadShot(enemy);
		break;
	}
	default: {

	}
	}
	currentEnergy += 5;
	if (currentEnergy > maxEnergy)
		currentEnergy = maxEnergy;
}


void Ranger::castBasicAttack(Enemy & enemy)
{
	enemy.setHealth(enemy.getHealth() - damage);
}

void Ranger::castHeadShot(Enemy & enemy)
{
	if (currentEnergy >= headShot.getCost() && headShot.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage * 2);
		currentEnergy -= headShot.getCost();
	}
}
