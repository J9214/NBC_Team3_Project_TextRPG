//Goblin.cpp
#include "Goblin.h"

Goblin::Goblin(int level) : Monster("Goblin", level) {
	this->health = randomBetween(30, 40);
	this->attack = randomBetween(10, 20);
}

void Goblin::takeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}