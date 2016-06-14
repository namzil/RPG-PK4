#include <iostream>
#include <cstdlib>
#include "curses.h"
#include "Sword.h"

Sword::Sword(char* nName, double nPrice, int lvl, int nDmg, double crit) {
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
	printw("\nNazwa: %s \n", name);
	printw("Wymagany lvl: %d \n",fromLvl);
	printw("Max obrazenia: %d \n",getDmg());
	printw("Szansa trafienia krytycznego: %d \n",critical);
	printw("Cena: %d \n",price);
}
