#pragma once
#include <iostream>
#include "Monster.h"

class BossMonster : public Monster {
public:
	BossMonster(int level);
	string getName() override { return name; }

	int getHealth() override { return health; }
	int getAttack() override { return attack; }
	void takeDamage(int damage) override;
};
