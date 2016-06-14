#include "Eatable.h"
#include <iostream>
#include <string>
#include "Player.h"
#include "curses.h"

using namespace std;

Eatable::Eatable(char* n, int hp, int mana, int energy, int rage, int lvl, int price) {
	name = n;
	hpRegen = hp;
	manaRegen = mana;
	energyRegen = energy;
	rageRegen = rage;
	fromLvl = lvl;
	price = price;
}

void Eatable::use(Player* player1) {
	if (fromLvl <= player1->getLevel()) {
		if (hpRegen != 0)
			player1->setCurrentHealth((player1->getCurrentHealth()) + hpRegen);
	}
}

void Eatable::showDescription() {
	clear();
	printw("Nazwa: %s \n", name);
	printw("Wymagany lvl: %d \n", fromLvl);
	if(hpRegen != 0)
		printw("HP: +%d\n",hpRegen);
	if(manaRegen != 0)
		printw("Mana: +%d \n",manaRegen);
	if (energyRegen != 0)
		printw("Energia: +%d \n", energyRegen);
	if (rageRegen != 0)
		printw("Furia: +%d \n",rageRegen);
	printw("CENA: %d \n\n", price);
}

char* Eatable::getName() {
	return name;
}