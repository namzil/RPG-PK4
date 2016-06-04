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
