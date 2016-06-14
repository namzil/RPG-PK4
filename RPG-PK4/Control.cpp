#include "Control.h"
#include "Map.h"
#include "curses.h"
#include "Game.h"
#include "Trader.h"


void Control::fight(Player* player, Map* objMap)
{
	Enemy wolf = Enemy("Wilk", 100, 20);
	char spell;
	clear();
	printw("HP wilka: %d\n\n", wolf.getHealth());
	player->writeStatistic();

	while (player->getCurrentHealth() > 0 && wolf.getHealth() > 0)
	{
		
		spell = getch();
		player->useSkill(spell, wolf);
		//wolf.setHealth(wolf.getHealth() - player->getDamage());
		if (wolf.getHealth() > 0)
			player->setCurrentHealth(player->getCurrentHealth() - wolf.doDamage(wolf.getDamage()));
		clear();
		printw("HP wilka: %d\n\n", wolf.getHealth());
		player->writeStatistic();
		//system("pause");
	}
	if (player->getCurrentHealth() > 0)
	{
		system("pause");
		player->setExperience(player->getExperience() + 70);
		if (player->getExperience() >= player->getExpNextLevel())
			player->levelUp();
		if (player->getQuest().getIsActive()) 
			player->setQuest(player->getQuest().progress());
		objMap->drawMap();
		refresh();
		objMap->drawStatsGUI(player);
	}
	else player->dead();
}

void Control::quest(Player * player, Map * objMap)
{
	//clear();
	if (!player->getQuest().getIsActive())
	{
		Quest quest = Quest();
		quest.setIsActive(1);
		player->setQuest(quest);
	}
	objMap->drawMap();
	refresh();
	objMap->drawStatsGUI(player);
	//objMap->drawQuest(player);

	if (player->getQuest().getIsComplete())
	{
		player->setGold(player->getGold() + player->getQuest().getReward());
		player->setQuest(player->getQuest().complete());
		objMap->drawMap();
		refresh();
		objMap->drawStatsGUI(player);
	}
}


bool Control::detectColision(int x, int y, Map* objMap, Player* player) {

	int mapValue = objMap->mapArray[x][y];
	if (x> MAX_HEIGHT - 1 || x < 0 || y > MAX_WIDTH - 1 || y < 0)
		return false;
	else if (mapValue == M_WALL || mapValue == M_WATER || mapValue == M_FENCE) {
		return false;
	}
	else if (mapValue == M_NPC) {
		//scr_dump("mainWindow_dump");
		clear();
		Trader * objNPC = new Trader("Seller");
		objNPC->showItems(player);
		//scr_restore("mainWindow_dump");
		objMap->drawMap();
		objMap->drawStatsGUI(player);
		return true;
	}
	else if (mapValue == M_ENEMY) {
		// ENEMY ACTION
		//gameState = FIGHT;
		fight(player, objMap);
		return true;
	}
	else if (mapValue == M_QUEST) {
		// QUEST ACTION
		quest(player, objMap);
		return true;
	}
	else if (mapValue == M_TELEPORT) {
		clear();
		if (x == MAX_HEIGHT - 1) {
			//objMap->saveMap("Map1_dump");
			objMap->loadMap("2");
			objMap->drawMap();
			objMap->drawStatsGUI(player);
			//move(playerX, playerY);
			refresh();
		}
		else if (y == MAX_WIDTH - 1) {
			objMap->loadMap("3");
			objMap->drawMap();
			objMap->drawStatsGUI(player);
			//	objMap->drawStatsGUI(p);
			refresh();
		}
		else {
			objMap->loadMap("1");
			objMap->drawMap();
			objMap->drawStatsGUI(player);
			refresh();
		}

		return true;
	}
	else if (mapValue == 'S' - 48 || mapValue == 'H' - 48 || mapValue == 'O' - 48 || mapValue == 'P' - 48) {
		return false;
	}
	else
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
