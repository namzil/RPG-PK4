#include "Eatable.h"
#include <iostream>
#include <string>

using namespace std;

Eatable::Eatable(int hp, int mana, int energy, int rage, int lvl) {
	hpRegen = hp;
	manaRegen = mana;
	energyRegen = energy;
	rageRegen = rage;
	fromLvl = lvl;
}

void Eatable::use(Player* player1) {
	


}

void Eatable::showDescription() {
	cout << "Nazwa: " << name << endl;
	cout << "Wymagany lvl: " << fromLvl << endl;
	if(hpRegen != 0)
		cout << "HP: +" << hpRegen << endl;
	if(manaRegen != 0)
		cout << "Mana: +" << name << endl;
	if(energyRegen != 0)
		cout << "Energia: +" << energyRegen << endl;
	if (rageRegen != 0)
		cout << "Furia: +" << rageRegen << endl;
	cout << "Cena: " << price << endl;


}