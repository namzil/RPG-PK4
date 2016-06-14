#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"
#include "Player.h"

class Weapon :public Item {
private:
	int dmg;
public:
	void use(Player*);
	double virtual takeDamage()=0;
	void virtual showDescription()=0;
	void setDmg(int);
	int getDmg();
	char *getName();

};


#endif // !WEAPON_H