#pragma once
#include <iostream>
#include "Monster.h"

class BossMonster : public Monster {
public:
	// ������
	BossMonster(int playerlevel);

	// ���� ���� �Լ� �������̵�
	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }
	void takeDamage(int damage) override;
};
