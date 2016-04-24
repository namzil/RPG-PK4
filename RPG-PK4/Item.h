#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
class Player;
class Item {
protected:
	string name;
	double price;
	int fromLvl;
public:
	Item();
	double buy();
	double sell();
	virtual void use(Player*)=0;
	virtual void showDescription()=0;


};


#endif // !ITEM_H
