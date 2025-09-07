#include "Orc.h"

Orc::Orc(int level) : Monster("Orc", level) {
	setHealth();
	setAttack();

}

void Orc::takeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
		dropitem();
	}
}
