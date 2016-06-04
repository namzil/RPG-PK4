#include "Trader.h"

Trader::Trader(string n) : NPC(n)
{
}

Trader::~Trader()
{
}

Equipment Trader::getEquipment()
{
	return equipment;
}

void Trader::setEqupipment(Equipment e)
{
	equipment = e;
}

void Trader::showName()
{
}
