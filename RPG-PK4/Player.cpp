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
	gold = 100;
}

Player::~Player()
{
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
