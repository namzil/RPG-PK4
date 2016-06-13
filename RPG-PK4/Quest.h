#ifndef QUEST_H
#define QUEST_H


class Quest
{
private:
	char* name;
	double reward;
	bool isComplete;
	int count;

public:
	Quest();
	~Quest();

	void setName(char*);
	void setReward(double);
	void setIsComplete(bool);
	void setCount(int);

	char* getName();
	double getReward();
	bool getIsComplete();
	int setCount();
};


#endif