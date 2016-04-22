#include "Warrior.h"

Warrior::Warrior(string n) : Player(n)
{
	maxRage = 100;
	currentRage = 100;
}

Warrior::~Warrior()
{
}

void Warrior::writeStatistic()
{
	Player::writeStatistic();
	cout << "Wscieklosc: " << currentRage << "\\" << maxRage << "\n";
}
