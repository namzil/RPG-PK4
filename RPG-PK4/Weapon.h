#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon :public Item {
private:
	int dmg;
public:
	double virtual takeDamage()=0;
	void virtual showDescription()=0;
	void setDmg(int);
	int getDmg();

};


#endif // !WEAPON_H