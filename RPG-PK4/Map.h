#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>
#include "Player.h"
#include "curses.h"

#define MAX_WIDTH 70
#define MAX_HEIGHT 30

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
#define M_PLAYER 112-48 //gracz 'p'

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

#define MAX_ENEMY 15

using namespace std;

class Map {
private:
	char* mapName;
	int playerX=1;
	int playerY=2;
public:
	short int mapArray[MAX_HEIGHT][MAX_WIDTH];
	Map();
	void loadMap(string lvl);
	void randomEnemy();
	void setPlayer(int, int, Map*);
	void drawField(int);
	void drawMap();
	void saveMap();
	void resetMap();
	void setMapName(char*);
	void drawStatsGUI(Player*);
	char* getMapName();
	int getPlayerX();
	int getPlayerY();
	void setPlayerX(int);
	void setPlayerY(int);

};

#endif // !MAP_H
