#include "Mage.h"

//konstruktor
Mage::Mage(string n) : Player (n)
{
	proffesion = mage;
	maxHealth = 200;
	currentHealth = 200;
	maxMana = 200;
	currentMana = 200;
	intellect = 30;
	agility = 10;
	strenght = 10;
	updateDamage();
}

Mage::~Mage()
{
}

//wypisywanie statysk gracza
void Mage::writeStatistic()
{
	Player::writeStatistic();
	cout << "Mana: " << currentMana << "\\" << maxMana << "\n";
}


void Mage::castBasicAttack(Enemy enemy)
{
	enemy.setHealth(enemy.getHealth()-damage);
}

void Mage::useSkill(Enemy enemy, Skill s)
{
	if (s.getCanBeUsed())
		if (currentMana >= s.getCost())
		{
			castBasicAttack(enemy);
			currentMana -= s.getCost();
		}
		else
			cout << "Za malo many";
	else
		cout << "Nie mozesz uzywac tej umiejetnosci";
}
