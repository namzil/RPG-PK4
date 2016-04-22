#ifndef ITEM_H
#define ITEM_H

class Item {
private:
	string name;
	double price;
	int fromLvl;

public:
	Item();
	virtual void buy();
	virtual void sell();
	virtual void showDescription();

};





#endif // !ITEM_H
