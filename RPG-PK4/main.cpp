#include "Player.h"
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"
#include "Map.h"

#include <iostream>
#include <string>


using namespace std;

int main() {	
	string name;
	int prof;
//    Player gracz;
	cout << "Podaj nazwe gracza\n";
	cin >> name;
	cout << "Wybierz klase: 1.wojownik 2.lucznik 3.mag\n";
	cin >> prof;

	//im = al_load_bitmap("\BitMaps\test.bmp");
	/*switch (prof) {
		case 1: {
			Warrior gracz = Warrior(name);
			gracz.writeStatistic();
			cout << typeid(gracz).name() << "\n";
			break;
		}
		case 2: {
			Ranger gracz = Ranger(name);
			gracz.writeStatistic();
			cout << typeid(gracz).name() << "\n";
			break;
		}
		case 3: {
			Mage gracz = Mage(name);
			gracz.writeStatistic();
			cout << typeid(gracz).name() << "\n";
			break;
		}
	}*/


	Player* gracz;

	if (prof == 1)
		gracz = new Warrior(name);
	else if(prof == 2)
		gracz = new Ranger(name);
	else 
		gracz = new Mage(name);

	Map map1;
	map1.loadMap("1");
	map1.drawMap();
	map1.drawStatsGUI(gracz);

	//Warrior gracz = Warrior("Mrowka");
	
	//cout << gracz.getSkill()->getSkillName();

	//SkillTree* asd = new SkillTree[3];
	//cout<<gracz.getDamage()<<"\n";
	//delete[] asd;
	system("pause");
	return 0;
}