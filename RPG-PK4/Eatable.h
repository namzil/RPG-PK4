#ifndef EATABLE_H
#define EATABLE_H
#include "Item.h"
#include "Equipment.h"


class Eatable: public Item {
private:
	char * name;
	int hpRegen;
	int manaRegen;
	int energyRegen;
	int rageRegen;

public:
	Eatable(char *, int,int,int,int,int, int);
	void use(Player* );
	void showDescription();
	char* getName();

};

#endif // !EATABLE_H