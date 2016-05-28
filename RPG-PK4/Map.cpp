#include "Map.h"
#include <fstream>
#include <conio.h>
#include <cstdint>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#define RAND_MAX  

Map::Map() {};

void Map::randomEnemy() {
	srand(time(NULL));
		for (int i = 0; i < 10; i++) {
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
void Map::SetColorAndBackground(int ForgC, int BackC = 0)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}


void Map::drawMap() {
	for (int x = 0; x < MAX_HEIGHT; x++) {
		for (int y = 0; y < MAX_WIDTH; y++) {
			switch (mapArray[x][y])
			{
				case M_PATH:
					SetColorAndBackground(BROWN, BROWN);
					cout << ' ';
					break;
				case M_WALL:
					SetColorAndBackground(BLACK, WHITE);
					cout << '#';
					break;
				case M_FENCE:
					SetColorAndBackground(DARKGRAY, DARKGRAY);
					cout << ' ';
					break;
				case M_DOOR:
					SetColorAndBackground(YELLOW, YELLOW);
					cout << ' ';
					break;
				case M_CLSDOOR:
					SetColorAndBackground(YELLOW, RED);
					cout << ' ';
					break;
				case M_GRASS:
					SetColorAndBackground(LIGHTGREEN, GREEN );
					cout << 'G';
					break;
				case M_ENEMY:
					SetColorAndBackground(LIGHTGREEN, GREEN);
					cout << 'E';
					break;
				case M_NPC:
					SetColorAndBackground(LIGHTCYAN, BLACK);
					cout << '?';
					break;
				case M_FLOOR:
					SetColorAndBackground(BLACK, BLACK);
					cout << ' ';
					break;
				case M_WATER:
					SetColorAndBackground(BLUE, LIGHTBLUE);
					cout << '~';
					break;
				default:
					SetColorAndBackground(BLACK, WHITE);
					cout << (char)(mapArray[x][y]+48);
					break;
			}
		}
		cout << "\n";
	}
	SetColorAndBackground(WHITE, BLACK);
}

void Map::saveMap() {}

void Map::resetMap() {}

void Map::setMapName(string nName) {}

string Map::getMapName() { return mapName; }