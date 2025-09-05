#include "Troll.h"

Troll::Troll(int level) : Monster("Troll", level) { 
	setHealth();
	setAttack();
}

void Troll::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}
