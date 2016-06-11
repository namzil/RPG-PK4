#include "Enemy.h"

Enemy::Enemy(string n, int h, int d) : NPC(n)
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
	health = h;
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
