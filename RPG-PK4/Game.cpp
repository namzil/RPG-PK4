#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::fight(Player* p)
{
	Enemy wolf = Enemy("Wilk", 100, 20);
	
	while (p->getCurrentHealth() > 0 && wolf.getHealth() > 0)
	{
		cout << "HP: " << p->getCurrentHealth() << "\n" << "HP wilka: " << wolf.getHealth() << "\n";
		wolf.setHealth(wolf.getHealth() - p->getDamage());
		if (wolf.getHealth() > 0)
			p->setCurrentHealth(p->getCurrentHealth() - wolf.getDamage());
	}
}
