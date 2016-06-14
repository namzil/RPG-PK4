#include <iostream>
#include "Weapon.h"

void Weapon::use(Player* player1) {
	player1->setWeapon(this);
}

void Weapon::setDmg(int sDmg) {
	dmg = sDmg;
}

int Weapon::getDmg() {
	return dmg;
}

char* Weapon::getName() {
	return name;
}
//Weapon body