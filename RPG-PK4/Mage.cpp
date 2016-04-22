#include "Mage.h"

Mage::Mage(string n) : Player (n)
{
	maxMana = 200;
	currentMana = 200;
}

Mage::~Mage()
{
}

void Mage::writeStatistic()
{
	Player::writeStatistic();
	cout << "Wscieklosc: " << currentMana << "\\" << maxMana << "\n";
}
