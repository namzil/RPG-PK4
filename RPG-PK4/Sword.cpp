#include <iostream>
#include <cstdlib>
#include "Sword.h"

Sword::Sword(string nName, double nPrice, int lvl, int nDmg, double crit) {
	name = nName;
	price = nPrice;
	fromLvl = lvl;
	setDmg(nDmg);
	critical = crit;
}

double Sword::takeDamage(){
	double endDMG;
	double basicDMG =(rand() % getDmg());
	int criticalAdd;
	if (critical >= 50)
		criticalAdd = rand() % 2;
	else if ((critical >= 35) && (critical < 50))
		criticalAdd = rand() % 3;
	else if ((critical >= 25) && (critical < 35))
		criticalAdd = rand() % 4;
	else if ((critical >= 20) && (critical < 25))
		criticalAdd = rand() % 5;
	else if ((critical >= 12) && (critical < 20))
		criticalAdd = rand() % 8;
	else if ((critical >= 6) && (critical < 12))
		criticalAdd = rand() % 16;
	else if (critical < 6)
		criticalAdd = rand() % 32;
	if (criticalAdd == 1)
		return endDMG = (basicDMG + getDmg() / 2);
	else
		return basicDMG;
}

void Sword::showDescription() {
	cout << "Nazwa: " << name << endl;
	cout << "Wymagany lvl: " << fromLvl << endl;
	cout << "Max obrazenia: " << getDmg() << endl;
	cout << "Szansa trafienia krytycznego: " << critical << endl;
	cout << "Cena: " << price << endl;
}
