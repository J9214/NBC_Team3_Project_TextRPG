#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Monster::Monster(string name, int level) : name(name), level(level), health(0), attack(0) {}

void Monster::setHealth(float multiply) {
	health = static_cast<int>(static_cast<float>(randomBetween(30, 40)) * multiply);
}

void Monster::setAttack(float multiply) {
	attack = static_cast<int>(static_cast<float>(randomBetween(5, 10)) * multiply);;
}

Item* Monster::dropitem() {
	static std::random_device rd;
	if (rd() % 2 == 1) {
		return new AttackBoost();
	}
	return new HealthPotion();
}

int Monster::randomBetween(int minVal, int maxVal) {
	minVal *= level;
	maxVal *= level;
	static std::random_device rd;
	return rd() % (maxVal - minVal + 1) + minVal;
}
