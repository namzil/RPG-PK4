#include <iostream>
#include "Mage.h"
#include "Ranger.h"
#include "Warrior.h"

using namespace std;

int main() {

	Warrior gracz = Warrior("Mrowka");
	gracz.writeStatistic();


	system("pause");
	return 0;
}