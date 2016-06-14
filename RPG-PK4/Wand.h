#ifndef WAND_H
#define WAND_H
#include "Wand.h"
#include "Weapon.h"
#include "Player.h"

class Wand : public Weapon {
private:
	int manaCost;
	int magicDamage;
	double critical;
	double blockChance;
public:
	Wand(char* name, double price, int lvl, int mCost, int dmg, int mDmg, double bc, double crit);
	double takeDamage();
	double takeMagicDamage(Player*);
	void showDescription();
};


#endif // !WAND_H
