#ifndef QUEST_H
#define QUEST_H


class Quest
{
private:
	char* name;
	double reward;
	bool isComplete;
	int count;
	bool isActive;

public:
	Quest();
	~Quest();

	Quest progress();
	Quest complete();

	void setName(char*);
	void setReward(double);
	void setIsComplete(bool);
	void setCount(int);
	void setIsActive(bool);

	char* getName();
	double getReward();
	bool getIsComplete();
	int getCount();
	bool getIsActive();
};


#endif