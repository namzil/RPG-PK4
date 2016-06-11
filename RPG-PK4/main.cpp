#include "Player.h"
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"
#include "NPC.h"
#include "Enemy.h"

#include "Map.h"
#include "Control.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "curses.h"

using namespace std;

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
		gracz.levelUp();
		cout << endl;
		gracz.writeStatistic();
		gracz.levelUp();
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	case 2: {
		Ranger gracz = Ranger(name);
		gracz.writeStatistic();
		gracz.levelUp();
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	case 3: {
		Mage gracz = Mage(name);
		gracz.writeStatistic();
		gracz.levelUp();
		gracz.writeStatistic();
		cout << typeid(gracz).name() << "\n";
		break;
	}
	}

/*	if (prof == 1)
		gracz = new Warrior(name);
	else if(prof == 2)
		gracz = new Ranger(name);
	else 
		gracz = new Mage(name);*/

	Map* map1 = new Map();
	map1->loadMap("1");
	map1->drawMap();
	refresh();
	map1->drawStatsGUI(gracz);
	bool flag = true;

	
	keypad(stdscr, TRUE);
	Control controler;
	while (flag = true) {
		cbreak();
		noecho();
		controler.catchEvents(map1);

	}

	//delete name;
	//delete prof2;
	system("pause");
	return 0;
}


