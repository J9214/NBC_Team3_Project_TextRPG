#include "AttackBoost.h"
#include "Character.h"
#include <cmath>

AttackBoost::AttackBoost() :
	Item("AttackBoost", 15),
	attackIncrease(10)
{}

void AttackBoost::use(Character* character)
{
	character->setAttack(character->getAttack() + attackIncrease);
}

Item* AttackBoost::clone()
{
	return new AttackBoost(*this);
}
