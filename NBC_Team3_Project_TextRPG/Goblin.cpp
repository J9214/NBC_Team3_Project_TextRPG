//Goblin.cpp
#include "Goblin.h"

Goblin::Goblin(int playerlevel) 
	: Monster("Goblin", playerlevel)
{ 
	setHealth();
	setAttack();
}

void Goblin::takeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}