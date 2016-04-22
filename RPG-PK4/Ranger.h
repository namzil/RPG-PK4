#ifndef RANGER_H
#define RANGER_H


#include "Player.h"


class Ranger : public Player {
private:
	int maxEnergy;
	int actuallEnergy;

public:
	Ranger(string);
	~Ranger();
	void writeStatistic();
};



#endif