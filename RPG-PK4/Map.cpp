#include "Map.h"
#include "Player.h"
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define MAX_ENEMY 15

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

void Map::loadMap(string lvl) {
	ifstream inFile;
	char tmpIn;
	inFile.open("..//Maps//Level" + lvl + ".txt");
	if (inFile.good()) {
		string nameLine;
		getline(inFile, nameLine);
		setMapName(nameLine);
		for (int x = 0; x < MAX_HEIGHT; x++) {
			for (int y = 0; y < MAX_WIDTH; y++) {
				inFile >> tmpIn; //czytanie pojedynczego znaku z pliku 
				mapArray[x][y] = (short int)tmpIn - 48; //zapis do tablicy jako int
			}
		}
		randomEnemy();
	}
	else
		cout << "I/O Error";
}

//funkjca ustawiajaca kolor konsoli
void Map::setColorAndBackground(int ForgC, int BackC = 0)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

void Map::drawStatsGUI(Player* player1) {

	for (int i = 0; i < MAX_WIDTH; i++)
		cout << "-";
	cout << "\n";
	player1->writeStatistic();
}

//rysowanie mapy w konsoli
void Map::drawMap() {
	system("cls");
	cout << getMapName() << "\n";
	for (int x = 0; x < MAX_HEIGHT; x++) {
		for (int y = 0; y < MAX_WIDTH; y++) {
			switch (mapArray[x][y])
			{
				case M_PATH:
					setColorAndBackground(BROWN, BROWN);
					cout << ' ';
					break;
				case M_WALL:
					setColorAndBackground(BLACK, WHITE);
					cout << '#';
					break;
				case M_FENCE:
					setColorAndBackground(DARKGRAY, DARKGRAY);
					cout << ' ';
					break;
				case M_DOOR:
					setColorAndBackground(YELLOW, YELLOW);
					cout << ' ';
					break;
				case M_CLSDOOR:
					setColorAndBackground(YELLOW, RED);
					cout << ' ';
					break;
				case M_GRASS:
					setColorAndBackground(LIGHTGREEN, GREEN );
					cout << 'G';
					break;
				case M_ENEMY:
					setColorAndBackground(LIGHTGREEN, GREEN);
					cout << 'E';
					break;
				case M_NPC:
					setColorAndBackground(LIGHTCYAN, BLACK);
					cout << '?';
					break;
				case M_FLOOR:
					setColorAndBackground(BLACK, BLACK);
					cout << ' ';
					break;
				case M_WATER:
					setColorAndBackground(BLUE, LIGHTBLUE);
					cout << '~';
					break;
				default:
					setColorAndBackground(BLACK, WHITE);
					cout << (char)(mapArray[x][y]+48);
					break;
			}
		}
		cout << "\n";
	}
	setColorAndBackground(WHITE, BLACK);
}




void Map::saveMap() {}

void Map::resetMap() {}

void Map::setMapName(string nName) {
	mapName = nName;
}

string Map::getMapName() {
	return mapName;
}