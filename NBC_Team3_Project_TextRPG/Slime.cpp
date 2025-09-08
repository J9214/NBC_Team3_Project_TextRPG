#include "Slime.h"

Slime::Slime(int playerlevel)
	: Monster("Slime", playerlevel)
{ 
	setHealth();
	setAttack();
}

void Slime::takeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}