#include "Troll.h"

Troll::Troll(int level) : Monster("Troll", level) {
	this->health = randomBetween(80, 120);   // Troll�� ü�� ���� ����
	this->attack = randomBetween(20, 30);    // ���ݷµ� ����
}

void Troll::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}
