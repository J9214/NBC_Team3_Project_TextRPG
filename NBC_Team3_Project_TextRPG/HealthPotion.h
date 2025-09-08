#pragma once
#include "Item.h"
#include <string>

class HealthPotion : public Item
{
private:
	int healthRestore;

public:
	HealthPotion();
	void use(Character* character) override;
	Item* clone() override;
};