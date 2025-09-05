#pragma once
#pragma once
#include <iostream>
#include "Monster.h"

class Troll : public Monster {
public:
	Troll(int level);
	int getHealth() override { return health; }
	int getAttack() override { return attack; }
	void takeDamage(int damage) override;
};
