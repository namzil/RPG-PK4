#include "Wand.h"
#include <iostream>
#include <string>
#include "curses.h"

using namespace std;

Wand::Wand(char* nName, double nPrice, int nLvl, int nMagCost, int nDmg, int nMagDmg, double nBc, double nCrit) {
	name = nName;
	price = nPrice;
	fromLvl = nLvl;
	manaCost = nMagCost;
	setDmg(nDmg);
	magicDamage = nMagDmg;;
	blockChance = nBc;
	critical = nCrit;
}

double Wand::takeDamage() {
	double* dmgTab= new double[2];
	double endDMG;
	double basicDMG = (rand() % getDmg());
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

double Wand::takeMagicDamage(Player* player1) {

	return (rand() % magicDamage);
}

void Wand::showDescription() {
	printw("\nNazwa: %s\n",name);
	printw("Wymagany lvl: %d \n",fromLvl);
	printw("Max obrazenia: %d \n",getDmg());
	printw("Max obra¿enia od magii: %d \n",magicDamage);
	printw("Koszt many: %d \n", manaCost);
	printw("Szansa uniku: %d \n", blockChance);
	printw("Szansa trafienia krytycznego: %d \n",critical);
	printw("CENA: %d \n",price);
}