#include "Ranger.h"

Ranger::Ranger(string n) : Player(n)
{
	maxEnergy = 100;
	currentEnergy = 100;
}

Ranger::~Ranger()
{
}

void Ranger::writeStatistic()
{
	Player::writeStatistic();
	cout << "Wscieklosc: " << currentEnergy << "\\" << maxEnergy << "\n";
}
