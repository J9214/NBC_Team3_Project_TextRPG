#include "Orc.h"

Orc::Orc(int playerlevel)
	: Monster("Orc", playerlevel)
{
	setHealth();
	setAttack();

}

void Orc::takeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}
