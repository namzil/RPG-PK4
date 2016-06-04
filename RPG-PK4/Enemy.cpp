#include "Enemy.h"

Enemy::Enemy(string n) : NPC(n)
{
}

Enemy::~Enemy()
{
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
