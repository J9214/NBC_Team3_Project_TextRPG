#include "HealthPotion.h"

HealthPotion::HealthPotion() :
	Item("HealthPotion"),
	healthRestore(50)
{}

void HealthPotion::use(Character * character)
{
	// Character�� getHp�� setHp �Լ��� �־�� ��.
	character->setHp(healthRestore);
}
