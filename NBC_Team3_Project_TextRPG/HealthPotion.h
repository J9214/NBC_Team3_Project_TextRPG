#pragma once
#include "Item.h"
#include <string>

class HealthPotion : public Item
{
private:
	int healthRestore;

public:
	HealthPotion();
	void Use(Character* character) override;
	Item* Clone() override;
};