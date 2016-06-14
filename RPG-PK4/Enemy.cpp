#include "Enemy.h"

Enemy::Enemy(char* n, int h, int d) : NPC(n)
{
	health = h;
	damage = d;
}

Enemy::~Enemy()
{
}

/*Enemy Enemy::spawnWolf()
{
	//Enemy wolf = Enemy("wilk");
	//wolf.damage = 20;
	//wolf.health = 100;
	return wolf;
}*/

int Enemy::doDamage(int damage)
{
	srand(time(NULL));
	return rand() % damage;
}

int Enemy::getHealth()
{
	return health;
}

int Enemy::getDamage()
{
	return damage;
}

Equipment Enemy::getEquipment()
{
	return equipment;
}

void Enemy::setHealth(int h)
{
	if (h > 0)
		health = h;
	else health = 0;
}

void Enemy::setDamage(int d)
{
	damage = d;
}

void Enemy::setEquipment(Equipment e)
{
	equipment = e;
}

void Enemy::showName()
{
}
