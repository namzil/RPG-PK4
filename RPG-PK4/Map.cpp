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


void Map::drawStatsGUI(Player* player1) {
	for (int i = 0; i < MAX_WIDTH; i++)
		printw("-");
	printw("\n");
	player1->writeStatistic();
}

void Map::drawField(int field) {
	switch (field)
	{
	case M_PATH:
		printw(" ");
		break;

	case M_WALL:
		printw("#");
		break;

	case M_FENCE:
		printw(" ");
		break;

	case M_DOOR:
		printw(" ");
		break;

	case M_CLSDOOR:
		printw(" ");
		break;

	case M_GRASS:
		printw("G");
		break;

	case M_ENEMY:
		printw("E");
		break;

	case M_NPC:
		printw("?");
		break;

	case M_FLOOR:
		printw(" ");
		break;

	case M_WATER:
		printw("~");
		break;

	case M_PLAYER:
		printw("P");
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