#include "Trader.h"
#include "Wand.h"
#include "Eatable.h"
#include "Sword.h"
#include "Bow.h"
#include "Item.h"
#include "Warrior.h"
#include "Ranger.h"
#include "Mage.h"
#include "curses.h"

Trader::Trader(char* n) : NPC(n)
{
	
}

Trader::~Trader()
{
}

void Trader::initShop() {

	Armor* a1 = new Armor("Steal Armor", 11, 0, 10, 2, 5);
	Armor* a2 = new Armor("Knight Armor", 40, 10, 20, 8, 10);
	eqArmor.insert(pair<int, Armor*>(1, a1));
	eqArmor.insert(pair<int, Armor*>(2, a2));

	Wand* w1 = new Wand("Basic Wand", 10, 0, 1, 5, 5, 2, 0);
	Wand* w2= new Wand("Incredible Wand", 20, 4, 1, 8, 10, 1, 0);
	eqWand.insert(pair<int, Wand*> (1, w1));
	eqWand.insert(pair<int, Wand*>(2, w2));

	Bow* b1 = new Bow("Bow", 15, 0, 10, 1, 1);
	Bow* b2 = new Bow("Crossbow", 30, 5, 15, 0, 8);
	eqBow.insert(pair<int, Bow*>(1, b1));
	eqBow.insert(pair<int, Bow*>(2, b2));

	Sword* s1 = new Sword("Cristal Sword", 10, 0, 10, 5);
	Sword* s2 = new Sword("Fire Sword", 20, 3,15,10);
	Sword* s3 = new Sword("Ace Sword", 30, 5, 20, 15);
	eqSword.insert(pair<int, Sword*>(1, s1));
	eqSword.insert(pair<int, Sword*>(2, s2));
	eqSword.insert(pair<int, Sword*>(3, s3));

	Eatable* e1 = new Eatable("HP Potion(+10hp)", 0, 0, 0, 0, 0, 0);
	Eatable* e2 = new Eatable("HP Potion(+20hp)", 20, 0, 0, 0, 10, 5);
	Eatable* e3 = new Eatable("Mana Potion(+10mana)", 0, 10, 0, 0, 0, 0);
	Eatable* e4 = new Eatable("Mana Potion(+20mana)", 0, 20, 0, 0, 10, 5);
	eqEatable.insert(pair<int, Eatable*>(1, e1));
	eqEatable.insert(pair<int, Eatable*>(2, e2));
	eqEatable.insert(pair<int, Eatable*>(3, e3));
	eqEatable.insert(pair<int, Eatable*>(4, e4));
}
void Trader::showItems(Player *p) {
	initShop();
		printw("Choose 1-Potions, 2-Swords, 3-Wands, 4-Bows, 5-Armors, q-exit: \n");
		refresh();
		char ch = getchar();
		if (ch == '1') {
			for (int i = 1; i <= eqEatable.size(); i++) {
				printw("%d. %s \n", i, eqEatable[i]->getName());
			}
			printw("\nPress 'e' to back");
			char ch2 = getch();

			if (((int)ch2 - 48 >= 0) && ((int)ch2 - 48 <= eqEatable.size())) {
				eqEatable[(int)ch2 - 48]->showDescription();

				char ch3 = getch();
				if (ch3 == 'b') {
					if ((p->getGold() >= eqEatable[(int)ch2 - 48]->buy()) && (p->getLevel() >= eqEatable[(int)ch2 - 48]->getLvl())) {
						p->addItem(eqEatable[(int)ch2 - 48]);
				}
					clear();
					showItems(p);
				}
			}
			refresh();

		}
		else if (ch == '2') {
			for (int i = 1; i <= eqSword.size(); i++) {
				printw("%d. %s \n", i, eqSword[i]->getName());
			}
			printw("\nPress 'e' to back");

				char ch2 = getch();
				if (((int)ch2 - 48 >= 0) && ((int)ch2 - 48 <= eqSword.size())) {
					eqSword[(int)ch2-48]->showDescription();
				char ch3 = getch();
				if (ch3 == 'b') {
					if ((p->getGold() >= eqSword[(int)ch2 - 48]->buy()) && (p->getLevel() >= eqSword[(int)ch2 - 48]->getLvl()))
					{
						p->setWeapon(eqSword[(int)ch2 - 48]);
						p->setGold(p->getGold() - eqSword[(int)ch2 - 48]->buy());
					}
					p->updateDamage();
					}
					clear();
					showItems(p);
				}
				refresh();
		}
		else if (ch == '3') {
			for (int i = 1; i <= eqWand.size(); i++) {
				printw("%d. %s \n", i, eqWand[i]->getName());
			}
			printw("\nPress 'e' to back");
			char ch2 = getch();
			if (((int)ch2 - 48 >= 0) && ((int)ch2 - 48 <= eqWand.size())) {
				eqWand[(int)ch2 - 48]->showDescription();
				char ch3 = getch();
				if (ch3 == 'b') {
					if ((p->getGold() >= eqWand[(int)ch2 - 48]->buy()) && (p->getLevel() >= eqWand[(int)ch2 - 48]->getLvl()))
						p->setWeapon(eqWand[(int)ch2 - 48]);
				}
				clear();
				showItems(p);
			}
			refresh();
		}
		else if (ch == '4') {
			for (int i = 1; i <= eqBow.size(); i++) {
				printw("%d. %s \n", i, eqBow[i]->getName());
			}
			printw("\nPress 'e' to back");
			char ch2 = getch();
			if (((int)ch2 - 48 >= 0) && ((int)ch2 - 48 <= eqBow.size())) {
				eqBow[(int)ch2 - 48]->showDescription();
				char ch3 = getch();
				if (ch3 == 'b') {
					if ((p->getGold() >= eqBow[(int)ch2 - 48]->buy()) && (p->getLevel() >= eqBow[(int)ch2 - 48]->getLvl()))
						p->setWeapon(eqBow[(int)ch2 - 48]);
				}
				clear();
				showItems(p);
			}
			refresh();
		}
		else if (ch == '5') {
			printw("1. Steal armor (0 lvl)\n");
			printw("2. Knight armor (10 lvl) \n");
			printw("Press 'b' to back \n");
			refresh();
			char ch2 = getch();
			if ((ch2 >= 0) && (ch2 <= eqArmor.size())) {
				eqArmor[(int)ch2 - 48]->showDescription();
			}
		}
		else if (ch == '6') {
			p->showEQ();

		}
		printw("q to exit");
		refresh();
		char opt2 = getch();
		if (opt2 == 'b') {
			clear();
			showItems(p);
		}
		else {
			//if(opt2 )

		}
		
}
void Trader::showName()
{
}
