#include "AttackBoost.h"
#include "Character.h"
#include <cmath>

AttackBoost::AttackBoost() :
	Item("AttackBoost", 15),
	attackIncrease(10)
{}

void AttackBoost::Use(Character* character)
{
	character->SetAttack(character->GetAttack() + attackIncrease);
}

Item* AttackBoost::Clone()
{
	return new AttackBoost(*this);
}
