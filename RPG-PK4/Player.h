#ifndef PLAYER_H
#define PLAYER_H

#include "Skill.h"
#include "Armor.h"
#include "Weapon.h"
#include "Enemy.h"
#include "SkillTree.h"
#include "Equipment.h"
#include "NPC.h"
#include "Enemy.h"
#include "Quest.h"
#include "curses.h"

#include <iostream>
#include <string>

class Weapon;
class Armor;

using namespace std;

enum  prof { warrior, mage, ranger };

class Player {

protected:
	char* name;
	prof proffesion;
	Equipment* equipment = new Equipment();
    Weapon* weapon;
	Armor* armor;
	int maxHealth;
	int currentHealth;
	int level;
	int experience;
	int expNextLevel;
	int strenght;
	int agility;
	int intellect;
	int damage;
	double gold;
	Quest quest;


public:
	Player(char*);
	~Player();

	virtual void writeStatistic() = 0;
	virtual void useSkill(char, Enemy &) = 0;

	virtual void levelUp() = 0;

	void takeDamage(int);
	void dead();  
	char* checkClass();
	void updateDamage();
	virtual void updateSkills() = 0;
	virtual void updatePlayer();


	char* getName();
	Equipment* getEquipment();
	Weapon* getWeapon();
	Armor* getArmor();
	int getMaxHealth();
	int getCurrentHealth();
	int getLevel();
	int getExperience();
	int getExpNextLevel();
	int getStrenght();
	int getAgility();
	int getIntellect();
	double getGold();
	int getDamage();
	Quest getQuest();

	void setName(char*);
	void setEquipment(Equipment*);
	void setWeapon(Weapon*);
	void setArmor(Armor*);
	void setMaxHealth(int);
	void setCurrentHealth(int);
	void setLevel(int);
	void setExperience(int);
	void setExpNextLevel(int);
	void setStrenght(int);
	void setAgility(int);
	void setIntellect(int);
	void setGold(double);
	void setQuest(Quest);
};


#endif