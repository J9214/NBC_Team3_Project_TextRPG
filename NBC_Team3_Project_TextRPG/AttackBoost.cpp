#include "AttackBoost.h"

AttackBoost::AttackBoost() :
	Item("AttackBoost"),
	attackIncrease(10)
{}

void AttackBoost::use(Character* character)
{
	// Character�� �Ͻ������� attack ���� ������Ű�� �Լ��� �־����.
	character->setAttack(attackIncrease);
}
