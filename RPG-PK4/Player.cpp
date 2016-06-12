#include "Player.h"
#include "curses.h"

//kostruktor
Player::Player(char* n) {

	name = new char[50];
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
	//delete [] skill;
	delete equipment;
	delete armor;
	delete weapon;
}

//wypisywanie statystyk gracza
void Player::writeStatistic()
{
	printw("Nazwa: %s ", name);
	printw("Klasa: %s \n", checkClass());
	printw("Poziom: %d ", level);
	printw("Doswiadczenie: %d \\ 100 \n", experience);
	printw("HP: %d \\ %d \n", currentHealth, maxHealth);
	printw("Sila: %d ", strenght);
	printw("Zrecznosc: %d \n", agility);
	printw("Inteligencja: %d ", intellect);
	printw("Obrazenia: %d \n", damage);
	refresh();
}

void Player::useSkill()
{
}

//sprawdzanie klasy gracza
char* Player::checkClass() {
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
	maxHealth += maxHealth*0.1;
	currentHealth = maxHealth;
	strenght += strenght*0.1;
	agility += agility*0.1;
	intellect += intellect*0.1;
	level += 1;
	experience -= experience;
	updatePlayer();
}

//aktualizacja obrazen
void Player::updateDamage()
{
	switch (proffesion) {
	case warrior: {
		damage = (strenght * 10 + agility * 3 + intellect) / 10;
			break;
		}
		case ranger: {
		damage = (agility * 10 + strenght * 2 + intellect * 2) / 10;
			break;
		}
		case mage: {
		damage = (intellect * 8 + strenght + agility * 3) / 10;
			break;
		}
		}
}


//aktualizacja postaci
void Player::updatePlayer() {
	updateSkills();
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


//************************GETTERY********************************

char* Player::getName()
{
	return name;
}

Equipment * Player::getEquipment()
{
	return equipment;
}

Weapon * Player::getWeapon()
{
	return weapon;
}

Armor * Player::getArmor()
{
	return armor;
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

int Player::getDamage()
{
	return damage;
}

void Player::setName(char* n)
{
	name = n;
}

void Player::setEquipment(Equipment* e)
{
	equipment = e;
}

void Player::setLevel(int l)
{
	level = l;
}

void Player::setExperience(int e)
{
	experience = e;
}

void Player::setStrenght(int s)
{
	strenght = s;
}

void Player::setAgility(int a)
{
	agility = a;
}

void Player::setIntellect(int i)
{
	intellect = i;
}

void Player::setGold(double g)
{
	gold = g;
}

void Player::setCurrentHealth(int h)
{
	currentHealth = h;
}

void Player::setMaxHealth(int mH)
{
	currentHealth = mH;
}

void Player::setArmor(Armor* a) 
{
	armor = a;

}

void Player::setWeapon(Weapon* w)
{
	weapon = w;

}