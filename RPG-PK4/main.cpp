#include <iostream>
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"
#include "SkillTree.h"

using namespace std;

int main() {

	Warrior gracz = Warrior("Mrowka");
	gracz.writeStatistic();
	cout << typeid(gracz).name();

	system("pause");
	return 0;
}