#pragma once
#include <iostream>

using namespace std;

class Monster {
private:

public:
	virtual string getName() = 0;
	virtual int getHealth() = 0;
	virtual int getAttack() = 0;
	virtual void takeDamage(int damage) = 0;
};