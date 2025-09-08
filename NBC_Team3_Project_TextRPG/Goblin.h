#pragma once
#include <iostream>
#include "Monster.h"

class Goblin : public Monster 
{
public:

	Goblin(int playerlevel);


	string GetName() const override { return name; }
	int GetHealth() const override { return health; }
	int GetAttack() const override { return attack; }
	void TakeDamage(int damage) override;
};