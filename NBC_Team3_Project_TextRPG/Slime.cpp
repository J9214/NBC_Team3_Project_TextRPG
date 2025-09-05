#include "Slime.h"

Slime::Slime(int level) : Monster("Slime", level) { 
	setHealth();
	setAttack();

}

void Slime::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}