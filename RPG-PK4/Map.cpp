#include "Map.h"
#include <fstream>
#include <conio.h>
#include <cstdint>
#include <windows.h>

//definicje kolorów
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15

//funkjca ustawiajaca kolor konsoli
void SetColorAndBackground(int ForgC, int BackC = 0)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

Map::Map() {
	mapName = new char[50];

};

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
	}
	else
		cout << "I/O Error";
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
					cout << 'G';
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