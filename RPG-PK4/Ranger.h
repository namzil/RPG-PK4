#ifndef RANGER_H
#define RANGER_H


#include "Player.h"


class Ranger : public Player {
private:
	int maxEnergy;
	int currentEnergy;

public:
	Ranger(string);
	~Ranger();
	void writeStatistic();
};



#endif