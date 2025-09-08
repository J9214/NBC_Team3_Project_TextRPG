#include "Troll.h"

Troll::Troll(int playerlevel)
	: Monster("Troll", playerlevel)
{ 
	SetHealth();
	SetAttack();

}

void Troll::TakeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}