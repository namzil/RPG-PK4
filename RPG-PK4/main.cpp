#include "Player.h"
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"
#include "NPC.h"
#include "Enemy.h"

#include <iostream>
#include <string>


using namespace std;

void fight(Player* gracz, Enemy* wilk)
{
	bool stillFighting = 1;
	while (stillFighting)
	{
		cout << "Wybierz umiejetnosc\n";
		gracz->useSkill();
		system("pause");
	}
}

int main() {
	string name;
	int prof;

	cout << "Podaj nazwe gracza\n";
	cin >> name;
	cout << "Wybierz klase: 1.wojownik 2.lucznik 3.mag\n";
	cin >> prof;

	switch (prof) {
	case 1: {
		Warrior gracz = Warrior(name);
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	case 2: {
		Ranger gracz = Ranger(name);
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	case 3: {
		Mage gracz = Mage(name);
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	}



/*	Player* gracz;

	if (prof == 1)
		gracz = new Warrior(name);
	else if(prof == 2)
		Ranger gracz = Ranger(name);
	else 
		Mage gracz = Mage(name);*/


	//Warrior gracz = Warrior("Mrowka");
	
	









	//cout << gracz.getSkill()->getSkillName();

	//SkillTree* asd = new SkillTree[3];
	//cout<<gracz.getDamage()<<"\n";
	//delete[] asd;
	system("pause");
	return 0;
}