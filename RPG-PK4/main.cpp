#include "Player.h"
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"
#include "Map.h"
#include "Control.h"
#include <iostream>
#include <string>
#include <windows.h>
#include "curses.h"



using namespace std;

int main() {	
	initscr();
	nocbreak();
	start_color();
	char* name = new char[30];
	char* prof2 = new char[4];
	printw("Podaj nazwe gracza\n");
	refresh();
	getstr(name);
	printw("Wybierz klase: 1.wojownik 2.lucznik 3.mag\n");
	refresh();
	int prof = int(getstr(prof2));
	Player* gracz;

	if (prof == 1)
		gracz = new Warrior(name);
	else if(prof == 2)
		gracz = new Ranger(name);
	else 
		gracz = new Mage(name);

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

	delete name;
	delete prof2;
	system("pause");
	return 0;
}


