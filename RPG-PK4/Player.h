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
	Equipment equipment;
	SkillTree* skillTree = new SkillTree[3];
	//Weapon weapon;
	//Armor armor;
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
	void levelUp();
	//int takeDamage();
	string getName();
	Equipment getEquipment();
	SkillTree* getSkillTree();
	//Weapon getWeapon();
	//Armor getArmor();
	int getMaxHealth();
	int getActualHealth();
	int getLevel();
	int getExperience();
	int getStrenght();
	int getAgility();
	int getIntellect();
	double getGold();
	
};


#endif