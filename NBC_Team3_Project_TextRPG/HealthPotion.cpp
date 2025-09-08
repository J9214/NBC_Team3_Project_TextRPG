#include "HealthPotion.h"
#include "Character.h"
#include <algorithm>
using namespace std;

HealthPotion::HealthPotion() :
	Item("HealthPotion" ,10),
	healthRestore(50)
{}

void HealthPotion::use(Character * character)
{
	int hp = min(character->getMaxHealth(), character->getHealth() + healthRestore);
	character->setHealth(hp);
}

Item* HealthPotion::clone()
{
	return new HealthPotion(*this);
}
