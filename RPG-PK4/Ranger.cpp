#include "Ranger.h"

Ranger::Ranger(string n) : Player(n)
{
	proffesion = ranger;
	maxEnergy = 100;
	currentEnergy = 100;
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
