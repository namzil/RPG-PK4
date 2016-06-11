#include "Warrior.h"
#include "curses.h"


//kostruktor
Warrior::Warrior(char* n) : Player(n)
{
	name = n;
	proffesion = warrior;
	maxHealth = 400;
	currentHealth = 400;
	maxRage = 100;
	currentRage = 100;
	strenght = 25;
	agility = 15;
	intellect = 10;
	updateDamage();
}

Warrior::~Warrior()
{
}


//wypisywanie statystyk
void Warrior::writeStatistic()
{
	Player::writeStatistic();
	printw("Wscieklosc: %d \\ %d \n", currentRage, maxRage);
}
