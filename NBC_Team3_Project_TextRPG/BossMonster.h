#pragma once
#include <iostream>
#include "Monster.h"

class BossMonster : public Monster {
public:
	// 생성자
	BossMonster(int playerlevel);

	// 순수 가상 함수 오버라이드
	string getName() const override { return name; }
	int getHealth() const override { return health; }
	int getAttack() const override { return attack; }
	void takeDamage(int damage) override;
};
