#pragma once
#include <iostream>
#include <random>
using namespace std;

class Monster 
{
protected:
	string name;
	int level;
	int health;
	int attack;
public:

	Monster(string monsterName, int playerlevel);


	virtual ~Monster() = default;


	virtual string GetName() const = 0;
	virtual int GetHealth() const = 0;
	virtual int GetAttack() const = 0;
	virtual void TakeDamage(int damage) = 0;


	void SetHealth(float multiply = 1.0);
	void SetAttack(float multiply = 1.0);
	int RandomBetween(int minVal, int maxVal);
};