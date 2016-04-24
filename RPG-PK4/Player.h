#ifndef PLAYER_H
#define PLAYER_H

#include "Skill.h"
#include "SkillTree.h"
#include "Equipment.h"
#include <iostream>
#include <string>


using namespace std;

enum  prof { warrior, mage, ranger };

class SkillTree;

class Player {
	//*********MEMBERS***************************
protected:
	string name;
	prof proffesion;
	//Equipment* equip = new Equipment();
	Skill* skill = new Skill[3];
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
	void dead();  //metoda do zrobienia
	string checkClass();
	void updateDamage();

	void updatePlayer();

	string getName();
	Equipment* getEquipment();
	Skill* getSkill();
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