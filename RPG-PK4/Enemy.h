#ifndef ENEMY_H
#define ENEMY_H


#include "NPC.h"

using namespace std;

class Enemy : public NPC {
private:
	int health;
	int damage;

public:
	Enemy();
	~Enemy();

	int getHealth();
	int getDamage();

	void setHealth(int);
	void setDamage(int);

	void v();
};

#endif