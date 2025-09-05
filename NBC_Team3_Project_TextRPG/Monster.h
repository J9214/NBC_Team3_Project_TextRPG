//Monster.h
#pragma once
#include <iostream>
#include <random>
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
using namespace std;

class Monster {

protected:
	string name;
	int level;
	int health;
	int attack;
public:
	Monster(string name, int level) : name(name), level(level), health(0), attack(0) 
	{ }
	virtual ~Monster() = default;

	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

	void setHealth(float multiply = 1.0) {
		health = static_cast<int>(static_cast<float>(randomBetween(30, 40)) * multiply);
	}

	void setAttack(int multiply = 1) {
		attack = static_cast<int>(static_cast<float>(randomBetween(5, 10)) * multiply);;
	}

	Item* dropitem() { 
		static std::random_device rd;
		if (rd() % 2 == 1) {
			return new AttackBoost();
		}
		return new HealthPotion();
	}

	int randomBetween(int minVal, int maxVal) {
		minVal *= level;
		maxVal *= level;
		static std::random_device rd;
		return rd() % (maxVal - minVal + 1) + minVal;
	}

};