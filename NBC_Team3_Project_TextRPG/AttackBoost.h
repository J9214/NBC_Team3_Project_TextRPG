#pragma once
#include "Item.h"
#include <string>

class AttackBoost : public Item
{
private:
	int attackIncrease;

public:
	AttackBoost();
	void Use(Character* character) override;
	Item* Clone() override;
};