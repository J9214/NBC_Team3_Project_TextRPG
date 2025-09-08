#pragma once
#include <iostream>
#include <random>
using namespace std;

class Monster {
protected:
	string name;
	int level;
	int health;
	int attack;
public:
	// 생성자
	Monster(string monsterName, int playerlevel);

	// 소멸자
	virtual ~Monster() = default;

	// 순수 가상 함수
	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

	// 일반 함수
	void setHealth(float multiply = 1.0);
	void setAttack(float multiply = 1.0);
	int randomBetween(int minVal, int maxVal);
};