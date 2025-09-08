#include "Troll.h"

Troll::Troll(int playerlevel)
	: Monster("Troll", playerlevel)
{ 
	setHealth();
	setAttack();

}

void Troll::takeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}