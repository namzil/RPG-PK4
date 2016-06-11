#include "Mage.h"
#include "curses.h"

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
	updateDamage();
}

Mage::~Mage()
{
}

//wypisywanie statysk gracza
void Mage::writeStatistic()
{
	Player::writeStatistic();
	printw("Mana %d \\ %d \n", currentMana, maxMana);
}
