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
	// ������
	Monster(string monsterName, int playerlevel);

	// �Ҹ���
	virtual ~Monster() = default;

	// ���� ���� �Լ�
	virtual string getName() const = 0;
	virtual int getHealth() const = 0;
	virtual int getAttack() const = 0;
	virtual void takeDamage(int damage) = 0;

	// �Ϲ� �Լ�
	void setHealth(float multiply = 1.0);
	void setAttack(float multiply = 1.0);
	int randomBetween(int minVal, int maxVal);
};