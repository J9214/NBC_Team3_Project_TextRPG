#include "Orc.h"

Orc::Orc(int level) : Monster("Orc", level) {
	this->health = randomBetween(50, 70);   // Orc는 Goblin보다 체력이 높음
	this->attack = randomBetween(15, 25);  // 공격력도 더 강함
}

void Orc::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}
