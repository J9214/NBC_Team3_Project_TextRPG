//Goblin.h
#pragma once
#include <iostream>
#include <random>
#include "Monster.h"

class Goblin : public Monster {
private:
	string name;
public:
	Goblin(int level);
	//string getName() override { return name; }
	int getHealth() override { return health; }
	int getAttack() override { return attack; }
	void takeDamage(int damage);
};