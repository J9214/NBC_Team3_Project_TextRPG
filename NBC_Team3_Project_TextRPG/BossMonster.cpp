//Goblin.cpp
#include "BossMonster.h"

BossMonster::BossMonster(int level) : Monster("BossMonster", level) {
	//this->health = Monster::getHealth() * 1.5;
	//this->attack = Monster::getAttack() * 1.5;
}

void BossMonster::takeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}