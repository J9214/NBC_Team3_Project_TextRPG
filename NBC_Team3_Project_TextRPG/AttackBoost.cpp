#include "AttackBoost.h"

AttackBoost::AttackBoost() :
	Item("AttackBoost"),
	attackIncrease(10)
{}

void AttackBoost::use(Character* character)
{
	// Character에 일시적으로 attack 값을 증가시키는 함수가 있어야함.
	character->setAttack(attackIncrease);
}
