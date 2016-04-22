#ifndef ITEM_H
#define ITEM_H

class Item {
protected:
	string name;
	double price;
	int fromLvl;

public:
	Item();
	virtual double buy();
	virtual double sell();
	virtual void showDescription();

};


#endif // !ITEM_H
