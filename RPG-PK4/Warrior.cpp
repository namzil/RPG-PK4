#include "Warrior.h"

Warrior::Warrior(string n) : Player(n)
{
	proffesion = warrior;
	maxRage = 100;
	currentRage = 100;
	updateDamage();
}

Warrior::~Warrior()
{
}

void Warrior::writeStatistic()
{
	Player::writeStatistic();
	cout << "Wscieklosc: " << currentRage << "\\" << maxRage << "\n";
}
