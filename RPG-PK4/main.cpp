#include "Player.h"
#include "Mage.h"
#include "Enemy.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"
#include "NPC.h"
#include "Enemy.h"
#include "Game.h"

#include "Map.h"
#include "Control.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "curses.h"

using namespace std;

int main() {	
	//string name;
	//int prof;

	//cout << "Podaj nazwe gracza\n";
	//cin >> name;
	//cout << "Wybierz klase: 1.wojownik 2.lucznik 3.mag\n";
	//cin >> prof;
/*
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
	}*/

/*	if (prof == 1)
		gracz = new Warrior(name);
	else if(prof == 2)
		gracz = new Ranger(name);
	else 
		gracz = new Mage(name);*/
	Game gra = Game();
	initscr();
	nocbreak();
	char* name = new char[30];
	char prof;
	printw("Podaj nazwe gracza\n");
	refresh();
	getstr(name);
	printw("Wybierz klase: 1.wojownik 2.lucznik 3.mag\n");
	refresh();
	prof = getch();
	Player* gracz;

	if (prof == '1')
		gracz = new Warrior(name);
	else if(prof == '2')
		gracz = new Ranger(name);
	else 
		gracz = new Mage(name);

	Map* map1 = new Map();
	map1->loadMap("1");
	map1->drawMap();
	refresh();
	map1->drawStatsGUI(gracz);
	//gra.fight(gracz);
	bool flag = true;
	

	keypad(stdscr, TRUE);
	Control controler;
	while (flag = true) {
		cbreak();
		noecho();
		controler.catchEvents(map1,gracz);
		
	}

	delete name;
	system("pause");
	return 0;
}


