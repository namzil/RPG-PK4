#include "Ranger.h"

//kostruktor
Ranger::Ranger(string n) : Player(n)
{
	proffesion = ranger;
	maxHealth = 300;
	currentHealth = 300;
	maxEnergy = 150;
	currentEnergy = 150;
	agility = 20;
	strenght = 15;
	intellect = 15;
	updateDamage();
}

Ranger::~Ranger()
{
}

//wypisywanie statystyk
void Ranger::writeStatistic()
{
	Player::writeStatistic();
	cout << "Energia: " << currentEnergy << "\\" << maxEnergy << "\n";
}

void Ranger::levelUp()
{
	Player::levelUp();
	maxEnergy = maxEnergy*0.1;
	currentEnergy = maxEnergy;
}

void Ranger::updateSkills()
{
}
