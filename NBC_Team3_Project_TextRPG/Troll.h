#pragma once
#pragma once
#include <iostream>
#include "Monster.h"

class Troll : public Monster {
public:
	Troll(int level);

	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }

	void takeDamage(int damage) override;
};
