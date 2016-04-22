#ifndef MAGE_H
#define MAGE_H


#include "Player.h"


class Mage : public Player {
private:
	int maxMana;
	int actuallMana;

public:
	Mage(string);
	~Mage();
	void writeStatistic();
};



#endif