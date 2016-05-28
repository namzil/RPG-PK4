#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>

#define MAX_WIDTH 70
#define MAX_HEIGHT 35

//definicje symboli na mapie
#define M_PATH 0 //sciezka
#define M_WALL 1 //sciana
#define M_FENCE 2 //drzwi
#define M_CLSDOOR 3 //zamkniete drzwi
#define M_ENEMY 4 //wróg
#define M_GRASS 5 //trawa
#define M_NPC 6 //NPC
#define M_DOOR 7 //drzwi
#define M_FLOOR 8 //pod³oga
#define M_WATER 9 //woda


//definicje kolorów konsoli
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

using namespace std;

class Map {
private:
	string mapName;
public:
	short int mapArray[MAX_HEIGHT][MAX_WIDTH];
	Map();
	void loadMap(string lvl);
	void randomEnemy();
	void drawMap();
	void saveMap();
	void resetMap();
	void setMapName(string);
	void SetColorAndBackground(int ForgC, int BackC);
	string getMapName();
};

#endif // !MAP_H
