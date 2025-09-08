#pragma once
#include <iostream>
#include "Monster.h"

class Goblin : public Monster {
public:
	// ������
	Goblin(int playerlevel);

	// ���� ���� �Լ� �������̵�
	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }

	void takeDamage(int damage);
};