#pragma once
#pragma once
#include <iostream>
#include "Monster.h"

class Orc : public Monster {
public:
	Orc(int level);
	int getHealth() override { return health; }
	int getAttack() override { return attack; }
	void takeDamage(int damage) override;
};
