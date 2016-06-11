#include "Control.h"
#include "Map.h"
#include "curses.h"
#include "Game.h"


void Control::fight(Player* player)
{
	Enemy wolf = Enemy("Wilk", 100, 20);

	while (player->getCurrentHealth() > 0 && wolf.getHealth() > 0)
	{
		cout << "HP: " << player->getCurrentHealth() << "\n" << "HP wilka: " << wolf.getHealth() << "\n";
		wolf.setHealth(wolf.getHealth() - player->getDamage());
		if (wolf.getHealth() > 0)
			player->setCurrentHealth(player->getCurrentHealth() - wolf.getDamage());
	}
}


bool Control::detectColision(int x, int y, Map* objMap, Player* player) {

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
		//gameState = FIGHT;
		objMap->fight(player);
		return true;
	}
	else if (mapValue == M_TELEPORT) {
		// TELEPORT ACTION
		return true;
	}
	else if (mapValue == 'S'-48 || mapValue == 'H'-48 || mapValue == 'O'-48 || mapValue == 'P'-48) {
		return false;
	}else
		return true;
}



void Control::catchEvents(Map* objMap, Player* player) {
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
	if (detectColision(currX + nDeltaX, currY + nDeltaY, objMap, player))
	{
		// If allowed, move in the direction specified
		objMap->setPlayer(nDeltaX, nDeltaY, objMap);
		objMap->setPlayerX(currX + nDeltaX);
		objMap->setPlayerY(currY + nDeltaY);
	}
}
