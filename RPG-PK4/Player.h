#ifndef PLAYER_H
#define PLAYER_H

#include "Skill.h"
#include "Armor.h"
#include "Weapon.h"
#include "SkillTree.h"
#include "Equipment.h"
#include "NPC.h"
#include "Enemy.h"
#include "Quest.h"
#include "curses.h"
#include "Eatable.h"

#include <iostream>
#include <string>
#include <map>
#include <ctime>

class Weapon;
class Armor;

using namespace std;

enum  prof { warrior, mage, ranger };

class Player {

protected:
	char* name;
	prof proffesion;
	map<int, Eatable*> equip;
//	Skill* skill = new Skill[3];
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
	Player() {};
	~Player();

	virtual void writeStatistic() = 0;
	virtual void useSkill(char, Enemy &) = 0;

	virtual void levelUp() = 0;

	int doDamage(int);
	void dead();  
	char* checkClass();
	void updateDamage();
	virtual void updateSkills() = 0;
	virtual void updatePlayer();


	char* getName();
//	Equipment* getEquipment();
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
	int getLvl();
	double getGold();
	int getDamage();
	Quest getQuest();

	void setName(char *);
	//void setEquipment(Equipment);
//	void setSkill(Skill*);
	void setMaxHealth(int);
	void setCurrentHealth(int);
	void setLevel(int);
	void setExperience(int);
	void setExpNextLevel(int);
	void setStrenght(int);
	void setAgility(int);
	void setIntellect(int);
	void setArmor(Armor*);
	void setWeapon(Weapon*);
	void setEquipment(Eatable* );
	void addItem(Eatable*);
	void showEQ();
	void setGold(double);
	void setQuest(Quest);
};


#endif