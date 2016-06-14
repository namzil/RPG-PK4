#include "NPC.h"
#include <typeinfo.h>
#include "curses.h"
NPC::NPC(char* n)
{	
	name = n;
}

NPC::~NPC()
{


}

void NPC::showItems(Player *p) {
	if (typeid(p).name() == "class Warrior") {
	printw("%s", typeid(p).name());


	}
	else if (typeid(p).name() == "class Ranger") {
		printw("1. Arrow 1pcs");

	}
	else {
		printw("1. Mana Potion(+10mana)");
	}
	getch();
}

