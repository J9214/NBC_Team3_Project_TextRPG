//Goblin.h
#pragma once
#include <iostream>
#include <random>
#include "Monster.h"

class Goblin : public Monster {
public:
	Goblin(int level);
	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }
	void takeDamage(int damage);
};