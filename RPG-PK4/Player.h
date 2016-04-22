#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;


class Player {
	//*********MEMBERS***************************
protected:
	string name;
	int maxHealth;
	int actuallHealth;
	int level;
	int experience;
	int strenght;
	int agility;
	int intellect;
	double gold;
	double damage;

public:
	Player(string);
	~Player();
	virtual void writeStatistic() = 0;
	int takeDamage();
};


#endif