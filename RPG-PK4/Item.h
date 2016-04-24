#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item {
protected:
	string name;
	double price;
	int fromLvl;
public:
	Item();
	double buy();
	double sell();
	virtual void showDescription();

};


#endif // !ITEM_H
