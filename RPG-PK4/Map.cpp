#include "Map.h"
#include "Player.h"
#include "Control.h"
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "curses.h"

Map::Map() {};

void Map::randomEnemy() {
	srand(time(NULL));
		for (int i = 0; i < MAX_ENEMY; i++) {
			int x = rand() % 29;
			int y = rand() % 69;
			if (mapArray[x][y] == 5) //jesli wylosowane pole jest traw¹ to ustaw wroga
				mapArray[x][y] = 4;
		}
}


void Map::setPlayer(int dX, int dY, Map* objMap) {
	int prevField = objMap->mapArray[playerX][playerY];
	move(playerX + 2, playerY);
	drawField(prevField);
	refresh();
	move(playerX+2+dX, playerY+dY);
	prevField = mapArray[playerX + dX][playerY + dY];
	drawField(M_PLAYER);
	refresh();
}

void Map::loadMap(string lvl) {
	ifstream inFile;
	char tmpIn;
	inFile.open("..//Maps//Level" + lvl + ".txt");
	if (inFile.good()) {
		string nameLine;
		getline(inFile, nameLine);
		for (int x = 0; x < MAX_HEIGHT; x++) {
			for (int y = 0; y < MAX_WIDTH; y++) {
				inFile >> tmpIn; //czytanie pojedynczego znaku z pliku 
				mapArray[x][y] = (short int)tmpIn - 48; //zapis do tablicy jako int
				if (mapArray[x][y] == M_PLAYER) {
					playerX = x;
					playerY = y;
					mapArray[x][y] = M_PATH;
				}
			}
		}
		randomEnemy();
	}
	else
		printw("I/O Error");
}

void Map::drawFight(Enemy enemy)
{
	for (int i = 0; i < MAX_WIDTH; i++)
		printw("-");
	printw("\n");
	cout << "HP wilka: " << enemy.getHealth();
}


void Map::drawStatsGUI(Player* player1) {
	for (int i = 0; i < MAX_WIDTH; i++)
		printw("-");
	printw("\n");
	player1->writeStatistic();
}

void Map::drawField(int field) {
	start_color();
	init_pair(1,COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	init_pair(5, COLOR_WHITE, COLOR_GREEN);
	init_pair(6, COLOR_RED, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_YELLOW);
	init_pair(8, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
	init_pair(10, COLOR_BLACK, COLOR_RED);
	switch (field)
	{
	case M_PATH:
		attron(COLOR_PAIR(1));
		printw(" ");
		attroff(COLOR_PAIR(1));
		break;

	case M_WALL:
		attron(COLOR_PAIR(2));
		printw("#");
		attroff(COLOR_PAIR(2));
		break;

	case M_FENCE:
		attron(COLOR_PAIR(9));
		printw(".");
		attroff(COLOR_PAIR(9));
		break;

	case M_DOOR:
		attron(COLOR_PAIR(4));
		printw(" ");
		attroff(COLOR_PAIR(4));
		break;

	case M_TELEPORT:
		attron(COLOR_PAIR(10));
		printw("T");
		attroff(COLOR_PAIR(10));
		break;

	case M_GRASS:
		attron(COLOR_PAIR(5));
		printw("G");
		attroff(COLOR_PAIR(5));
		break;

	case M_ENEMY:
		attron(COLOR_PAIR(5));
		printw("E");
		attroff(COLOR_PAIR(5));
		break;

	case M_NPC:
		attron(COLOR_PAIR(6));
		printw("?");
		attroff(COLOR_PAIR(6));
		break;

	case M_FLOOR:
		attron(COLOR_PAIR(3));
		printw(" ");
		attroff(COLOR_PAIR(3));
		break;

	case M_WATER:
		attron(COLOR_PAIR(8));
		printw("~");
		attroff(COLOR_PAIR(8));
		break;

	case M_PLAYER:
		attron(COLOR_PAIR(7));
		printw("P");
		attroff(COLOR_PAIR(7));
		break;

	default:
		char z = (char)(field + 48);
		printw("%c", z);
		break;
	}
}

//rysowanie mapy w konsoli
void Map::drawMap() {
	system("cls");
	for (int x = 0; x < MAX_HEIGHT; x++) {
		for (int y = 0; y < MAX_WIDTH; y++)
			drawField(mapArray[x][y]);
		printw("\n");
	}
}

void Map::saveMap() {}

void Map::resetMap() {}

void Map::setMapName(char* nName) {
	nName = new char[40];
	mapName = nName;
}



char* Map::getMapName() {
	return mapName;
}

int Map::getPlayerX() {
	return playerX;
}
int Map::getPlayerY(){
	return playerY;
}

void Map::setPlayerX(int x) {
	playerX = x;
}

void Map::setPlayerY(int y) {
	playerY = y;
}