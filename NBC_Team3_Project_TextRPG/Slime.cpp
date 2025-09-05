#include "Slime.h"

Slime::Slime(int level) : Monster("Slime", level) {
	this->health = randomBetween(10, 20);   
	this->attack = randomBetween(5, 10); 
}

void Slime::takeDamage(int damage) {
	health -= damage;
	if (health < 0) health = 0;
}