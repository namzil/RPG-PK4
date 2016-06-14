#ifndef NPC_H
#define NPC_H

#include "Player.h"
#include <iostream>
#include <string>


using namespace std;

class NPC {
private:
	char* name;

public:
	NPC(char*);
	~NPC();
	virtual void showName() = 0;
	void showItems(Player* p);
	void sell(Player* p);
	void buy(Player* p);
};

#endif