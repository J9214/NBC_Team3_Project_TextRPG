#pragma once
#include <iostream>
#include "Monster.h"

class Slime : public Monster {
public:
	Slime(int level);

	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }
	void takeDamage(int damage) override;
};
