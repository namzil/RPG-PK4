#include "Player.h"


//kostruktor
Player::Player(string n) {
	name = n;
	//maxHealth = 300;
	//currentHealth = 300;
	level = 0;
	experience = 0;
	//strenght = 10;
	//agility = 10;
	//intellect = 10;
	gold = 100.0;
	//skill[0].unlockSkill("Atak podstawowy");
}

Player::~Player()
{
	delete [] skill;
//	delete equip;
}

//wypisywanie statystyk gracza
void Player::writeStatistic()
{
	cout << "Nazwa: " << name << "\n";
	cout << "Klasa: " << checkClass() << "\n";
	cout << "Poziom: " << level << "\n";
	cout << "Doswiadczenie: " << experience << "\\" << 100 << "\n";
	cout << "HP: " << currentHealth <<"\\" << maxHealth << "\n";
	cout << "Sila: " << strenght << "\n";
	cout << "Zrecznosc: " << agility << "\n";
	cout << "Inteligencja: " << intellect << "\n";
	cout << "Obrazenia: " << damage << "\n";
}

//sprawdzanie klasy gracza
string Player::checkClass() {
	if (proffesion == warrior)
		return "wojownik";
	else if (proffesion == ranger)
		return "lucznik";
	else if (proffesion == mage)
		return "mag";
}

//zdobycie nastepnego poziomu
void Player::levelUp()
{
	maxHealth = maxHealth*0.1;
	currentHealth = maxHealth;
	level += 1;
	experience -= experience;
}

//aktualizacja obrazen
void Player::updateDamage()
{
	switch (proffesion) {
		case warrior:{  
			damage = (strenght * 10 + agility*3 + intellect)/10 ;
			break;
		}
		case ranger: {
			damage = (agility * 10 + strenght * 2 + intellect * 2)/10;
			break;
		}
		case mage: {
			damage = (intellect * 8 + strenght + agility*3)/10;
			break;
		}
		}
}

//aktualizacja postaci
void Player::updatePlayer() {
	updateDamage();
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

/*Equipment* Player::getEquipment()
{
	return equip;
}*/

Skill* Player::getSkill()
{
	return skill;
}

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
