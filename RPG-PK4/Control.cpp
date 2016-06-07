#include "Control.h"
#include "Map.h"
#include "curses.h"

bool Control::detectColision(int x, int y, Map* objMap) {

	int mapValue = objMap->mapArray[x][y];
	if (x> MAX_HEIGHT || x < 1  || y > MAX_WIDTH || y < 1)
		return false;
	else if (mapValue == M_WALL || mapValue == M_WATER || mapValue == M_FENCE) {
		return false;
	}
	else if (mapValue == M_NPC) {
		//NPC ACTION
		return true;
	}
	else if (mapValue == M_ENEMY) {
		// ENEMY ACTION
		return true;
	}
	else if (mapValue == 'S'-48 || mapValue == 'H'-48 || mapValue == 'O'-48 || mapValue == 'P'-48) {
		return false;
	}else
		return true;
}

void Control::catchEvents(Map* objMap) {
	int nDeltaX=0;
	int nDeltaY=0;

	int ch = getch();
	switch (ch)
	{
		// Move up
		case KEY_UP:
			nDeltaX = -1;
			nDeltaY = 0;
			break;
		// Move left
		case KEY_LEFT:
			nDeltaX = 0;
			nDeltaY = -1;
			break;
		// Move right
		case KEY_RIGHT:
			nDeltaX = 0;
			nDeltaY = 1;
			break;
		// Move down
		case KEY_DOWN:
			nDeltaX = 1;
			nDeltaY = 0;
			break;
		// Escape key
		case CONSOLE_KEY_QUIT:
		// Quit the program
		return;
		// Ignore all other keys
		default:
			break;
	}

	int currX = objMap->getPlayerX();
	int currY = objMap->getPlayerY();
	if (detectColision(currX + nDeltaX, currY + nDeltaY, objMap))
	{
		// If allowed, move in the direction specified
		objMap->setPlayer(nDeltaX, nDeltaY, objMap);
		objMap->setPlayerX(currX + nDeltaX);
		objMap->setPlayerY(currY + nDeltaY);
	}
}
