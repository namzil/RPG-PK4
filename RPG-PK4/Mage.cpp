#include "Mage.h"

Mage::Mage(string n) : Player (n)
{
	proffesion = mage;
	maxMana = 200;
	currentMana = 200;
	updateDamage();
}

Mage::~Mage()
{
}

void Mage::writeStatistic()
{
	Player::writeStatistic();
	cout << "Mana: " << currentMana << "\\" << maxMana << "\n";
}
