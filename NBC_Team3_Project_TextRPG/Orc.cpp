#include "Orc.h"

Orc::Orc(int playerlevel)
	: Monster("Orc", playerlevel)
{
	SetHealth();
	SetAttack();

}

void Orc::TakeDamage(int damage) 
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
	}
}
