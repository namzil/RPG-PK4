#ifndef EATABLE_H
#define EATABLE_H
#include "Item.h"
#include "Equipment.h"

class Eatable: public Item {
private:
	int hpRegen;
	int manaRegen;
	int energyRegen;
	int rageRegen;

public:
	Eatable(int,int,int,int,int);
	double buy();
	double sell();
	void showDescription();

};

#endif // !EATABLE_H