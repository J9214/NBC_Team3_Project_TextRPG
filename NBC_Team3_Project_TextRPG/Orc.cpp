#include "Orc.h"

Orc::Orc(int playerLevel)
	: Monster("Orc", playerLevel)
{
	SetHealth();
	SetAttack();
}