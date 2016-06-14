#include "Warrior.h"


//kostruktor
Warrior::Warrior(char* n) : Player(n)
{
	proffesion = warrior;
	maxHealth = 400;
	currentHealth = 400;
	maxRage = 100;
	currentRage = 0;
	strenght = 25;
	agility = 15;
	intellect = 10;
	updatePlayer();
}

Warrior::~Warrior()
{
}


//wypisywanie statystyk
void Warrior::writeStatistic()
{
	Player::writeStatistic();
	//cout << "Wscieklosc: " << currentRage << "\\" << maxRage << "\n";
	printw("Wscieklosc: %d\\%d\n\n",currentRage,maxRage);
	showSkills();
	if (quest.getIsActive())
		printw("\n\nZADANIE Zabite wilki: %d\\5\n", quest.getCount());
	if (quest.getIsComplete())
		printw("ZAKONCZONO. WROC PO NAGRODE");
	refresh();
}

void Warrior::levelUp()
{
	Player::levelUp();
}

void Warrior::updateSkills()
{
	if (level >= basicAttack.getLevelRequired())
		basicAttack.setCanBeUsed(1);
	if (level >= heroicStrike.getLevelRequired())
		heroicStrike.setCanBeUsed(1);
	if (level >= bloodlust.getLevelRequired())
		bloodlust.setCanBeUsed(1);
}

void Warrior::useSkill(char spell, Enemy & enemy)
{
	switch (spell)
	{
	case '1': {
		castBasicAttack(enemy);
		break;
	}
	case '2': {
		castHeroicStrike(enemy);
		break;
	}
	case '3': {
		castBloodlust(enemy);
		break;
	}
	default: {

	}
	}
}

void Warrior::castBasicAttack(Enemy & enemy)
{
	enemy.setHealth(enemy.getHealth() - doDamage(damage));
	currentRage += 5;
	if (currentRage > maxRage)
		currentRage = maxRage;
}

void Warrior::castHeroicStrike(Enemy & enemy)
{
	if (currentRage >= heroicStrike.getCost() && heroicStrike.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - doDamage(damage) *2);
		currentRage -= heroicStrike.getCost();
	}
}

void Warrior::castBloodlust(Enemy & enemy)
{
	if (currentRage >= bloodlust.getCost() && bloodlust.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - doDamage(damage) * 2);
		currentRage -= bloodlust.getCost();
		currentHealth += damage;
	}
}
