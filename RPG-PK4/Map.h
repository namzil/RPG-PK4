#ifndef MAP_H
#define MAP_H
#include <iostream>
#include <string>

#define MAX_WIDTH 70
#define MAX_HEIGHT 35
//opis symboli na mapie
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
using namespace std;

class Map {
private:
	string mapName;
public:
	short int mapArray[MAX_HEIGHT][MAX_WIDTH];
	Map();
	void loadMap(string lvl);
	void drawMap();
	void saveMap();
	void resetMap();
	void setMapName(string);
	string getMapName();
};

#endif // !MAP_H
