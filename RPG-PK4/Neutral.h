#ifndef NEUTRAL_H
#define NEUTRAL_H

#include "NPC.h"


class Neutral : public NPC
{
public:
	Neutral(string);
	~Neutral();
	void showName();
};

#endif