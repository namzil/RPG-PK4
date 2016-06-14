#include "Player.h"
#include "Eatable.h"
#include "curses.h"

//kostruktor
Player::Player(char* n) {

	name = new char[50];
	name = n;
	level = 0;
	experience = 0;
	expNextLevel = 100;
	gold = 100.0;
	quest = Quest();
}

Player::~Player()
{
	//delete [] skill;
//	delete equipment;
	delete armor;
	delete weapon;
}

//wypisywanie statystyk gracza
void Player::writeStatistic()
{
	printw("Nazwa: %s ", name);
	printw("Klasa: %s \n", checkClass());
	printw("Poziom: %d ", level);
	printw("Doswiadczenie: %d \\ %d \n", experience, expNextLevel);
	printw("HP: %d \\ %d \n", currentHealth, maxHealth);
	if (weapon)
		printw("Bron: %s\n",weapon->getName());
	printw("Sila: %d ", strenght);
	printw("Zrecznosc: %d \n", agility);
	printw("Inteligencja: %d ", intellect);
	printw("Obrazenia: %d \n", damage);
	printw("Zloto: %.0f\n", gold);
	//showSkills();
	//refresh();
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
	expNextLevel *= 2;
	updatePlayer();
}

//aktualizacja obrazen
void Player::updateDamage()
{
	switch (proffesion) {
	case warrior: {
		damage = (strenght * 10 + agility * 3 + intellect) / 10;
		if (weapon)
			damage += weapon->getDmg();
			break;
		}
		case ranger: {
		damage = (agility * 10 + strenght * 2 + intellect * 2) / 10 ;
		if (weapon)
			damage += weapon->getDmg();
			break;
		}
		case mage: {
		damage = (intellect * 8 + strenght + agility * 3) / 10 ;
		if (weapon)
			damage += weapon->getDmg();
			break;
		}
		}
}


//aktualizacja postaci
void Player::updatePlayer() {
	updateSkills();
	updateDamage();
}

int Player::doDamage(int damage)
{
	srand(time(NULL));
	return rand()%damage + 0.5*damage;
}

void Player::dead()
{
	clear();
	printw("Umarnales. Koniec gry...");
	//refresh();
}


//************************GETTERY********************************

char* Player::getName()
{
	return name;
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

int Player::getExpNextLevel()
{
	return expNextLevel;
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

Quest Player::getQuest()
{
	return quest;
}

void Player::setName(char* n)
{
	name = n;
}


void Player::setLevel(int l)
{
	level = l;
}

void Player::setExperience(int e)
{
	experience = e;
}

void Player::setExpNextLevel(int exp)
{
	expNextLevel = exp;
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

void Player::setQuest(Quest q)
{
	quest = q;
}

void Player::setCurrentHealth(int h)
{
	if (h > 0)
		currentHealth = h;
	else currentHealth = 0;
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

int Player::getLvl() {
	return level;

}

void Player::setEquipment(Eatable* obj) {
	
}

void Player::addItem(Eatable* obj) {
	equip.insert(pair<int, Eatable*>(1, obj));
}
void Player::showEQ() {
	for (int i = 1; (i <= equip.size()); i++) {
		printw("%s \n", equip[i]->getName());
	}
	refresh();
	getch();
}