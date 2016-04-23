#include "Ranger.h"

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

void Ranger::writeStatistic()
{
	Player::writeStatistic();
	cout << "Energia: " << currentEnergy << "\\" << maxEnergy << "\n";
}
