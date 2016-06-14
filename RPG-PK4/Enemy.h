#ifndef ENEMY_H
#define ENEMY_H


#include "NPC.h"

#include <ctime>


using namespace std;

class Enemy : public NPC {
private:
	int health;
	int damage;
	Equipment equipment;

public:
	Enemy(char*, int, int);
	~Enemy();

	//Enemy spawnWolf();

	int doDamage(int);

	int getHealth();
	int getDamage();
	Equipment getEquipment();

	void setHealth(int);
	void setDamage(int);
	void setEquipment(Equipment);

	void showName();
};

#endif