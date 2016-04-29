#ifndef SWORD_H
#define SWORD_H
#include "Weapon.h"
#include <string>

using namespace std;

class Sword :public Weapon {
private:
	double critical;
public:
	Sword(string name, double price, int lvl, int dmg, double crit);
	double takeDamage();
	void showDescription();

};



#endif
