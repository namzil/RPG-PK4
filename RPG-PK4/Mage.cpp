#include "Mage.h"
#include "curses.h"
#include "Enemy.h"

//konstruktor
Mage::Mage(char* n) : Player (n)
{
	name = n;
	proffesion = mage;
	maxHealth = 200;
	currentHealth = 200;
	maxMana = 200;
	currentMana = 200;
	intellect = 30;
	agility = 10;
	strenght = 10;
	updatePlayer();
}

Mage::~Mage()
{
}

//wypisywanie statysk gracza
void Mage::writeStatistic()
{
	Player::writeStatistic();
	cout << "Mana: " << currentMana << "\\" << maxMana << "\n";
	showSkills();
}

void Mage::levelUp()
{
	Player::levelUp();
	maxMana += maxMana*0.1;
	currentMana = maxMana;
}

void Mage::updateSkills()
{
	if (level >= basicAttack.getLevelRequired())
		basicAttack.setCanBeUsed(1);
	if (level >= heal.getLevelRequired())
		heal.setCanBeUsed(1);
	if (level >= fireBlast.getLevelRequired())
		fireBlast.setCanBeUsed(1);
}

void Mage::useSkill(char spell, Enemy & enemy)
{
	switch (spell)
	{
	case '1': {
		castBasicAtttack(enemy);
		break;
	}
	case '2': {
		castHeal();
		break;
	}
	case '3': {
		castFireBlast(enemy);
		break;
	}
	case '4': {
		castPyroblast(enemy);
		break;
	}
	default: {

	}
	}
}

void Mage::castBasicAtttack(Enemy & enemy)
{
	enemy.setHealth(enemy.getHealth() - damage);
}

void Mage::castHeal()
{
	if (currentMana >= heal.getCost())
	{
		currentHealth += 30;
		if (currentHealth > maxHealth)
			currentHealth = maxHealth;
		currentMana -= heal.getCost();
	}
	else
	{
		printw("Brak many");
		refresh();
	}
}

void Mage::castFireBlast(Enemy & enemy)
{
	if (currentMana >= fireBlast.getCost() && fireBlast.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage * 2);
		currentMana -= fireBlast.getCost();
	}
}

void Mage::castPyroblast(Enemy & enemy)
{
	if (currentMana >= pyroblast.getCost() && pyroblast.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage * 3);
		currentMana -= pyroblast.getCost();
	}
}
