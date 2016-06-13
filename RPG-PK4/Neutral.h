#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "NPC.h"
#include "Quest.h"
#include "Player.h"
#include "curses.h"


class Neutral : public NPC
{
private:
	Quest quest;
public:
	Neutral(string);
	~Neutral();
	void showName();
	void giveQuest(Player*);
};

#endif