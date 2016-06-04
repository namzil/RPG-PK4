#ifndef ENEMY_H
#define ENEMY_H


#include "NPC.h"

using namespace std;

class Enemy : public NPC {
private:
	int health;
	int damage;
	Equipment equipment;

public:
	Enemy(string);
	~Enemy();

	int getHealth();
	int getDamage();
	Equipment getEquipment();

	void setHealth(int);
	void setDamage(int);
	void setEquipment(Equipment);

	void showName();
};

#endif