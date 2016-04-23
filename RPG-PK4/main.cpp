#include "Player.h"
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"

#include <iostream>
#include <string>


using namespace std;

int main() {

	Warrior gracz = Warrior("Mrowka");
	gracz.writeStatistic();
	cout << typeid(gracz).name() <<"\n";
	cout << gracz.getSkillTree()->getSkillName();

	//SkillTree* asd = new SkillTree[3];
	//cout<<gracz.getDamage()<<"\n";
	//delete[] asd;
	system("pause");
	return 0;
}