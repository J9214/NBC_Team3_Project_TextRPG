#pragma once
#include <string>

class Monster 
{
protected:
	std::string name;
	int level;
	int health;
	int attack;

public:
	Monster(std::string monsterName, int playerlevel);
	virtual ~Monster() = default;

	std::string GetName() const;
	int GetHealth() const;
	int GetAttack() const;
	void TakeDamage(int damage);

	void SetHealth(float multiply = 1.0);
	void SetAttack(float multiply = 1.0);
	int RandomBetween(int minVal, int maxVal);
};