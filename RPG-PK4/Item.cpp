#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

//konstruktor
Item::Item() {}

void Item::use(Player* player1) {



}
//funkcja kup przedmiot
double Item::buy() {
	return price;
}

//funkcja sprzedaj przedmiot
double Item::sell() {
	return price;
}


//funkcja wyswietl opis przedmiotu

void Item::showDescription() {}

int Item::getLvl() {
	return fromLvl;
}
