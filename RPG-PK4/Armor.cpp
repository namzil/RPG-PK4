#include <iostream>
#include <string>
#include "Armor.h"

using namespace std;

//konstruktor
Armor::Armor(string nName, double nPrice, int nLvl, int nDef, int mDef, double bc) {
	name = nName;
	price = nPrice;
	fromLvl = nLvl;
	def = nDef;
	magicDef = mDef;
	blockChance = bc;
}

// wypisuje informaje o zbroi
void Armor::showDescription() {
	cout << "Nazwa: " << name << endl;
	cout << "Wymagany lvl: " << fromLvl << endl;
	cout << "Obrona: +" << def << endl;
	cout << "Obrona przed magia: +" << magicDef << endl;
	cout << "Szansa na zablokowanie: +" << blockChance << "%" << endl;
	cout << "Cena: " << price << endl;
}

