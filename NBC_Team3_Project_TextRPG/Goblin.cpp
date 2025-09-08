#include "Goblin.h"

Goblin::Goblin(int playerLevel)
	: Monster("Goblin", playerLevel)
{ 
	SetHealth();
	SetAttack();
}