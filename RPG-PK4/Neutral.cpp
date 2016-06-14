#include "Neutral.h"

Neutral::Neutral(char* n) : NPC(n)
{
	quest = Quest();
	quest.setIsActive(1);
}

Neutral::~Neutral()
{
}

void Neutral::showName()
{
	
}

void Neutral::giveQuest(Player * player)
{
	if (player->getQuest().getIsActive())
		printw("Juz masz zadanie\n");
	else
		player->setQuest(quest);
}
