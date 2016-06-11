#include "Warrior.h"


//kostruktor
Warrior::Warrior(string n) : Player(n)
{
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
	cout << "Wscieklosc: " << currentRage << "\\" << maxRage << "\n";
}
