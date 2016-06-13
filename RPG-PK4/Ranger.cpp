#include "Ranger.h"

//kostruktor
Ranger::Ranger(char* n) : Player(n)
{
	proffesion = ranger;
	maxHealth = 300;
	currentHealth = 300;
	maxEnergy = 150;
	currentEnergy = 150;
	agility = 20;
	strenght = 15;
	intellect = 15;
	updatePlayer();
}

Ranger::~Ranger()
{
}

//wypisywanie statystyk
void Ranger::writeStatistic()
{
	Player::writeStatistic();
	//cout << "Energia: " << currentEnergy << "\\" << maxEnergy << "\n";
	printw("Energia: %d\\%d\n",currentEnergy,maxEnergy);
	showSkills();
	if (quest.getIsActive())
		printw("\n\nZADANIE Zabite wilki: %d\\5\n", quest.getCount());
	if (quest.getIsComplete())
		printw("ZAKONCZONO. WROC PO NAGRODE");
	refresh();
}

void Ranger::levelUp()
{
	Player::levelUp();
	maxEnergy += maxEnergy*0.1;
	currentEnergy = maxEnergy;
}

void Ranger::updateSkills()
{
	if (level >= basicAttack.getLevelRequired())
		basicAttack.setCanBeUsed(1);
	if (level >= headShot.getLevelRequired())
		headShot.setCanBeUsed(1);
	if (level >= aimedShot.getLevelRequired())
		aimedShot.setCanBeUsed(1);
}

void Ranger::useSkill(char spell, Enemy & enemy)
{
	switch (spell)
	{
	case '1': {
		castBasicAttack(enemy);
		break;
	}
	case '2': {
		castHeadShot(enemy);
		break;
	}
	case '3': {
		castAimedShot(enemy);
		break;
	}
	default: {

	}
	}
	currentEnergy += 5;
	if (currentEnergy > maxEnergy)
		currentEnergy = maxEnergy;
}


void Ranger::castBasicAttack(Enemy & enemy)
{
	enemy.setHealth(enemy.getHealth() - damage);
}

void Ranger::castHeadShot(Enemy & enemy)
{
	if (currentEnergy >= headShot.getCost() && headShot.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage * 2);
		currentEnergy -= headShot.getCost();
	}
}

void Ranger::castAimedShot(Enemy & enemy)
{
	if (currentEnergy >= aimedShot.getCost() && aimedShot.getCanBeUsed())
	{
		enemy.setHealth(enemy.getHealth() - damage * 3);
		currentEnergy -= aimedShot.getCost();
	}
}
