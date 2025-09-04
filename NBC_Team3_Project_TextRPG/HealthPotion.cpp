#include "HealthPotion.h"

HealthPotion::HealthPotion() :
	Item("HealthPotion"),
	healthRestore(50)
{}

void HealthPotion::use(Character * character)
{
	// Character에 getHp와 setHp 함수가 있어야 함.
	character->setHp(healthRestore);
}
