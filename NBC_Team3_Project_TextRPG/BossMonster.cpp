#include "BossMonster.h"

BossMonster::BossMonster(int playerLevel)
	: Monster("Dragon", playerLevel)
{
	SetHealth(1.5);
	SetAttack(1.5);
}