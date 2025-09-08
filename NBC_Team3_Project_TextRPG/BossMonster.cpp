//Goblin.cpp
#include "BossMonster.h"

BossMonster::BossMonster(int playerlevel)
	: Monster("Dragon", playerlevel)
{
	setHealth(1.5);
	setAttack(1.5);
}

void BossMonster::takeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}