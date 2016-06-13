#include "Quest.h"

Quest::Quest()
{
	name = "Zabij wilki";
	count = 0;
	isActive = 0;
	isComplete = 0;
	reward = 50;
}

Quest::~Quest()
{
}

Quest Quest::progress()
{
	if (count < 5)
		count++;
	if (count == 5)
		isComplete = true;

	return *this;
}

Quest Quest::complete()
{
	isActive = false;
	isComplete = false;
	count = 0;
	return *this;
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

void Quest::setIsActive(bool active)
{
	isActive = active;
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

int Quest::getCount()
{
	return count;
}

bool Quest::getIsActive()
{
	return isActive;
}
