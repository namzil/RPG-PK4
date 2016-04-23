#ifndef ENEMY_H
#define ENEMY_H


#include "NPC.h"

using namespace std;

class Enemy : public NPC {
private:
	int health;
	double damage;

public:
	Enemy();
	~Enemy();
};

#endif