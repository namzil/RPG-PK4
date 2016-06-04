#ifndef NPC_H
#define NPC_H

#include "Equipment.h"
#include <iostream>
#include <string>



using namespace std;

class NPC {
private:
	string name;

public:
	NPC(string);
	~NPC();
	virtual void showName() = 0;
};

#endif