//Goblin.cpp
#include "BossMonster.h"

BossMonster::BossMonster(int playerlevel)
	: Monster("Dragon", playerlevel)
{
	SetHealth(1.5);
	SetAttack(1.5);
}

void BossMonster::TakeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}