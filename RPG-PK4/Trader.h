#ifndef TRADER_H
#define TRADER_H

#include "NPC.h"
#include "Equipment.h"

class Trader : public NPC
{
private:
	Equipment equipment;

public:
	Trader();
	~Trader();
};


#endif