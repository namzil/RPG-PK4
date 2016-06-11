#include "Control.h"
#include "Map.h"
#include "curses.h"

bool Control::detectColision(int x, int y, Map* objMap, Player* p) {

	int mapValue = objMap->mapArray[x][y];
	if (x> MAX_HEIGHT-1 || x < 0  || y > MAX_WIDTH-1 || y < 0)
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
	else if (mapValue == M_TELEPORT) {
		clear();
		if (x == MAX_HEIGHT-1) {
			//objMap->saveMap("Map1_dump");
			objMap->loadMap("2");
			objMap->drawMap();
			objMap->drawStatsGUI(p);
			//move(playerX, playerY);
			refresh();
		}
		else if (y == MAX_WIDTH-1) {
			objMap->loadMap("3");
			objMap->drawMap();
			objMap->drawStatsGUI(p);
		//	objMap->drawStatsGUI(p);
			refresh();
		}
		else {
			objMap->loadMap("1");
			objMap->drawMap();
			objMap->drawStatsGUI(p);
			refresh();
		}
			
		return true;
	}
	else if (mapValue == 'S'-48 || mapValue == 'H'-48 || mapValue == 'O'-48 || mapValue == 'P'-48) {
		return false;
	}else
		return true;
}

void Control::catchEvents(Map* objMap, Player* p) {
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
	if (detectColision(currX + nDeltaX, currY + nDeltaY, objMap, p))
	{
		// If allowed, move in the direction specified
		objMap->setPlayer(nDeltaX, nDeltaY, objMap);
		objMap->setPlayerX(currX + nDeltaX);
		objMap->setPlayerY(currY + nDeltaY);
	}
}
