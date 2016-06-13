#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "NPC.h"
#include "Quest.h"


class Neutral : public NPC
{
private:
	Quest quest;
public:
	Neutral(string);
	~Neutral();
	void showName();
};

#endif