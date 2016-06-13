#include "Quest.h"

Quest::Quest()
{
}

Quest::~Quest()
{
}

void Quest::setName(char * n)
{
	name = n;
}

void Quest::setReward(double r)
{
	reward = r;
}

void Quest::setIsComplete(bool i)
{
	isComplete = i;
}

void Quest::setCount(int c)
{
	count = c;
}

char * Quest::getName()
{
	return name;
}

double Quest::getReward()
{
	return reward;
}

bool Quest::getIsComplete()
{
	return isComplete;
}

int Quest::setCount()
{
	return count;
}
