#include "Player.h"

Player::Player(string n) {
	name = n;
	maxHealth = 300;
	actuallHealth = 300;
	level = 0;
	experience = 0;
	strenght = 10;
	agility = 10;
	intellect = 10;
	gold = 100.0;
	skillTree[0].unlockSkill("Atak podstawowy");
}

Player::~Player()
{
		delete[] skillTree;
}

void Player::writeStatistic()
{
	cout << "Nazwa: " << name << "\n";
	cout << "Poziom: " << level << "\n";
	cout << "Doswiadczenie: " << experience << "\\" << 100 << "\n";
	cout << "HP: " << actuallHealth <<"\\" << maxHealth << "\n";
	cout << "Sila: " << strenght << "\n";
	cout << "Zrecznosc: " << agility << "\n";
	cout << "Inteligencja: " << intellect << "\n";
}

void Player::levelUp()
{
	maxHealth = maxHealth*0.1;
	actuallHealth = maxHealth;
	level += 1;

}

string Player::getName()
{
	return name;
}

Equipment Player::getEquipment()
{
	return equipment;
}

SkillTree* Player::getSkillTree()
{
	return skillTree;
}

int Player::getMaxHealth()
{
	return maxHealth;
}

int Player::getActualHealth()
{
	return actuallHealth;
}

int Player::getLevel()
{
	return level;
}

int Player::getExperience()
{
	return experience;
}

int Player::getStrenght()
{
	return strenght;
}

int Player::getAgility()
{
	return agility;
}

int Player::getIntellect()
{
	return intellect;
}

double Player::getGold()
{
	return gold;
}
