//Goblin.cpp
#include "Goblin.h"

Goblin::Goblin(int playerlevel) 
	: Monster("Goblin", playerlevel)
{ 
	SetHealth();
	SetAttack();
}

void Goblin::TakeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}