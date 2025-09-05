#include "Slime.h"

Slime::Slime(int level) : Monster("Slime", level) {
	this->health = randomBetween(10, 20);   // Slime은 약함
	this->attack = randomBetween(5, 10);    // 공격력 낮음
}

void Slime::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}
