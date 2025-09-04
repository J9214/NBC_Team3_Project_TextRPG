//Monster.h
#pragma once
#include <iostream>

using namespace std;

class Monster {
private:
	string name;
	int level;
protected:
	int health;
	int attack;
public:
	Monster(string name, int level) : name(name), level(level), health(0), attack(0) {}
	virtual ~Monster() = default;

	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;

	int randomBetween(int minVal, int maxVal) {
		minVal *= level;
		maxVal *= level;
		srand(static_cast<unsigned int>(time(0)));
		return rand() % (maxVal - minVal + 1) + minVal;
	}
};