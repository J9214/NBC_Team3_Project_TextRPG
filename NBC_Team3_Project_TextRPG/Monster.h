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
	Monster(string name, int level);

	virtual ~Monster() = default;

	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

	void setHealth(float multiply = 1.0);

	void setAttack(float multiply = 1.0);

	Item* dropitem();

	int randomBetween(int minVal, int maxVal);

};