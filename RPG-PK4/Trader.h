#ifndef TRADER_H
#define TRADER_H

#include "NPC.h"
#include "Equipment.h"
#include <map>
#include "Eatable.h"
#include "Sword.h"
#include "Armor.h"
#include "Bow.h"
#include "Wand.h"

class Trader : public NPC
{
private:
	map<int, Eatable*> eqEatable;
	map<int, Sword*> eqSword;
	map<int, Bow*> eqBow;
	map<int, Wand*> eqWand;
	map<int, Armor*> eqArmor;
public:
	Trader(char*);
	~Trader();

	void initShop();
	void showName();
	void showItems(Player *p);
};


#endif