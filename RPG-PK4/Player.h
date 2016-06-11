#ifndef PLAYER_H
#define PLAYER_H

#include "Skill.h"
//#include "Armor.h"
//#include "Weapon.h"
#include "SkillTree.h"
#include "Equipment.h"
#include <iostream>
#include <string>

class Weapon;
class Armor;

using namespace std;

enum  prof { warrior, mage, ranger };

class SkillTree;

class Player {
	//*********MEMBERS***************************
protected:
	char* name;
	prof proffesion;
	//Equipment* equip = new Equipment();
	Skill* skill = new Skill[3];
    Weapon* weapon;
	Armor* armor;
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
	Player(char*);
	~Player();

	virtual void writeStatistic() = 0;
	void levelUp();
	void takeDamage(int);
	void dead();  //metoda do zrobienia
	char* checkClass();
	void updateDamage();

	void updatePlayer();

	char* getName();
	Equipment* getEquipment();
	Skill* getSkill();
	//Weapon* getWeapon();
	//Armor* getArmor();
	int getMaxHealth();
	int getCurrentHealth();
	int getLevel();
	int getExperience();
	int getStrenght();
	int getAgility();
	int getIntellect();
	double getGold();
	double getDamage();

	void setName(char *);
	//void setEquipment(Equipment);
	void setSkill(Skill*);
	void setMaxHealth(int);
	void setCurrentHealth(int);
	void setLevel(int);
	void setExperience(int);
	void setStrenght(int);
	void setAgility(int);
	void setIntellect(int);
	void setArmor(Armor*);
	void setWeapon(Weapon*);
};


#endif