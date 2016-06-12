#include "Warrior.h"


//kostruktor
Warrior::Warrior(char* n) : Player(n)
{
	proffesion = warrior;
	maxHealth = 400;
	currentHealth = 400;
	maxRage = 100;
	currentRage = 0;
	strenght = 25;
	agility = 15;
	intellect = 10;
	updatePlayer();
}

Warrior::~Warrior()
{
}


//wypisywanie statystyk
void Warrior::writeStatistic()
{
	Player::writeStatistic();
	cout << "Wscieklosc: " << currentRage << "\\" << maxRage << "\n";
	showSkills();
}

void Warrior::levelUp()
{
	Player::levelUp();
}

void Warrior::updateSkills()
{
	if (level >= basicAttack.getLevelRequired())
		basicAttack.setCanBeUsed(1);
	if (level >= heroicStrike.getLevelRequired())
		heroicStrike.setCanBeUsed(1);
}

void Warrior::useSkill(char spell, Enemy & enemy)
{
	switch (spell)
	{
	case '1': {
		castBasicAttack(enemy);
		break;
	}
	case '2': {
		castHeroicStrike(enemy);
		break;
	}
	default: {

	}
	}
}

void Warrior::castBasicAttack(Enemy & enemy)
{
	enemy.setHealth(enemy.getHealth() - damage);
	currentRage += 10;
	if (currentRage > maxRage)
		currentRage = maxRage;
}

void Warrior::castHeroicStrike(Enemy & enemy)
{
	if (currentRage >= heroicStrike.getCost() && heroicStrike.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage*2);
		currentRage -= 15;
	}
}
