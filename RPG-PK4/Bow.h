#ifndef BOW_H
#define BOW_H
#include "Weapon.h"

class Bow : public Weapon {
private:
	double blockChance;
	double critical;
public:
	Bow(string name, double price, int lvl, int dmg, double bc, double crit);
	double takeDamage();
	void showDescription();
};




#endif // ! BOW_H