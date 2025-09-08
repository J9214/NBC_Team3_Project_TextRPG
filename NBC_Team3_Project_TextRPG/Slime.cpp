#include "Slime.h"

Slime::Slime(int playerlevel)
	: Monster("Slime", playerlevel)
{ 
	SetHealth();
	SetAttack();
}

void Slime::TakeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}