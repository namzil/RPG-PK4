#include "Enemy.h"

Enemy::Enemy()
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

void Enemy::setHealth(int h)
{
	health = h;
}

void Enemy::setDamage(int d)
{
	damage = d;
}
