#include "Player.h"

Player::Player(string n) {
	name = n;
	maxHealth = 300;
	currentHealth = 300;
	level = 0;
	experience = 0;
	strenght = 10;
	agility = 10;
	intellect = 10;
	gold = 100.0;
	//skill[0].unlockSkill("Atak podstawowy");
}

Player::~Player()
{
	//	delete[] skill;
}

void Player::writeStatistic()
{
	cout << "Nazwa: " << name << "\n";
	cout << "Poziom: " << level << "\n";
	cout << "Doswiadczenie: " << experience << "\\" << 100 << "\n";
	cout << "HP: " << currentHealth <<"\\" << maxHealth << "\n";
	cout << "Sila: " << strenght << "\n";
	cout << "Zrecznosc: " << agility << "\n";
	cout << "Inteligencja: " << intellect << "\n";
}

void Player::levelUp()
{
	maxHealth = maxHealth*0.1;
	currentHealth = maxHealth;
	level += 1;

}

void Player::takeDamage(int damage)
{
	currentHealth = currentHealth - damage;
	if (currentHealth <= 0)
		dead();
}

void Player::dead()
{
	//koniec gry
}

string Player::getName()
{
	return name;
}

Equipment* Player::getEquipment()
{
	return equip;
}

/*SkillTree* Player::getSkillTree()
{
	return skill;
}*/

int Player::getMaxHealth()
{
	return maxHealth;
}

int Player::getCurrentHealth()
{
	return currentHealth;
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

double Player::getDamage()
{
	return damage;
}
