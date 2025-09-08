#pragma once
#include <iostream>
#include "Monster.h"

class Orc : public Monster {
public:
	// ������
	Orc(int playerlevel);

	// ���� ���� �Լ� �������̵�
	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }
	void takeDamage(int damage) override;
};
