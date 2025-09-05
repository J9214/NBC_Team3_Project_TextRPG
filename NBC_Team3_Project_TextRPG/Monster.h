//Monster.h
#pragma once
#include <iostream>

using namespace std;

class Monster {

protected:
	string name;
	int level;
	int health;
	int attack;
public:
	Monster(string name, int level) : name(name), level(level), health(), attack() {}
	virtual ~Monster() = default;

	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

	void setHealth(float multiply = 1.0) {
		health = static_cast<int>(static_cast<float>(randomBetween(20, 30)) * multiply);
	}

	void setAttack(int multiply = 1) {
		attack = static_cast<int>(static_cast<float>(randomBetween(5, 10)) * multiply);;
	}

	Item* dropitem() { 
		if (health <= 0) {

		}
		return nullptr;
	}

	int randomBetween(int minVal, int maxVal) {
		minVal *= level;
		maxVal *= level;
		//srand(static_cast<unsigned int>(time(0)));
		return rand() % (maxVal - minVal + 1) + minVal;
	}
};