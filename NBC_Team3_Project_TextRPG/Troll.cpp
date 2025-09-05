#include "Troll.h"

Troll::Troll(int level) : Monster("Troll", level) {
	this->health = randomBetween(80, 120);   // Troll은 체력 가장 많음
	this->attack = randomBetween(20, 30);    // 공격력도 강함
}

void Troll::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}