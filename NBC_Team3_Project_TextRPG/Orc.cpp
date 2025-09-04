#include "Orc.h"

Orc::Orc(int level) : Monster("Orc", level) {
	this->health = randomBetween(50, 70);   // Orc�� Goblin���� ü���� ����
	this->attack = randomBetween(15, 25);  // ���ݷµ� �� ����
}

void Orc::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}
