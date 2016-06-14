#include "Bow.h"
#include "curses.h"
#include <iostream>

Bow::Bow(char* nName, double nPrice, int nLvl, int nDmg, double nBc, double nCrit) {
	name = nName;
	price = nPrice;
	fromLvl = nLvl;
	setDmg(nDmg);
	blockChance = nBc;
	critical = nCrit;
}

double Bow::takeDamage() {
	double endDMG;
	double basicDMG = (rand() % getDmg());
	int criticalAdd;
	if (critical >= 50)
		criticalAdd = rand() % 3;
	else if ((critical >= 35) && (critical < 50))
		criticalAdd = rand() % 4;
	else if ((critical >= 25) && (critical < 35))
		criticalAdd = rand() % 5;
	else if ((critical >= 20) && (critical < 25))
		criticalAdd = rand() % 6;
	else if ((critical >= 12) && (critical < 20))
		criticalAdd = rand() % 7;
	else if ((critical >= 6) && (critical < 12))
		criticalAdd = rand() % 8;
	else if (critical < 6)
		criticalAdd = rand() % 9;
	if (criticalAdd == 1)
		return endDMG = (basicDMG + getDmg() / 2);
	else
		return basicDMG;
}

void Bow::showDescription() {
	printw("\nNazwa: %s \n", name);
	printw("Wymagany lvl: %d \n", fromLvl);
	printw("Max obrazenia: %d \n",getDmg());
	printw("Szansa uniku: %d \n", blockChance);
	printw("Szansa trafienia krytycznego: %d \n", critical);
	printw("CENA: %d \n",price);
}

