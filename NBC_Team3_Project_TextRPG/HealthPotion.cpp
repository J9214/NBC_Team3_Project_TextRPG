#include "HealthPotion.h"
#include "Character.h"
#include <algorithm>
using namespace std;

HealthPotion::HealthPotion()
	: Item("HealthPotion" ,10),
	healthRestore(50)
{
}

void HealthPotion::Use(Character * character)
{
	character->SetHealth(character->GetHealth() + healthRestore);
}

Item* HealthPotion::Clone()
{
	return new HealthPotion(*this);
}
