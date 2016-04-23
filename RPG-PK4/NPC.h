#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>


using namespace std;

class NPC {
private:
	string name;

public:
	NPC();
	~NPC();
	virtual void v() = 0;
};

#endif