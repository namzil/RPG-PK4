#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "Equipment.h"
#include "SkillTree.h"

using namespace std;


class Player {
	//*********MEMBERS***************************
protected:
	string name;
	Equipment* equip = new Equipment();
	SkillTree* skill = new SkillTree[3];
	//Weapon weapon;
	//Armor armor;
	int maxHealth;
	int currentHealth;
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
	void levelUp();
	void takeDamage(int);



	string getName();
	Equipment* getEquipment();
	SkillTree* getSkillTree();
	//Weapon getWeapon();
	//Armor getArmor();
	int getMaxHealth();
	int getCurrentHealth();
	int getLevel();
	int getExperience();
	int getStrenght();
	int getAgility();
	int getIntellect();
	double getGold();
	double getDamage();
	
};


#endif