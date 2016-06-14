#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

class Armor :public Item {
private:
	int def;
	int magicDef;
	double blockChance;
public:
	Armor(char* name, double price, int lvl, int def, int mDef, double blockChance);
	void use(Player*);
	void showDescription();

};


#endif // !ARMOR_H
