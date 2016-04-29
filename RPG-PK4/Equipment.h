#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <vector>
#include "Item.h"

class Equipment {
private:
	vector <Item*> itemList;

public:
	Equipment();
	void addItem(Item* );
};



#endif
