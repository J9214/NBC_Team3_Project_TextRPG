#include "Monster.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

Monster::Monster(string monsterName, int playerlevel)
	: name(monsterName), level(playerlevel), health(0), attack(0)
{}

void Monster::SetHealth(float multiply) 
{
	health = static_cast<int>(static_cast<float>(RandomBetween(20, 30)) * multiply);
}

void Monster::SetAttack(float multiply) 
{
	attack = static_cast<int>(static_cast<float>(RandomBetween(5, 10)) * multiply);
}

int Monster::RandomBetween(int minVal, int maxVal) 
{
	minVal *= level;
	maxVal *= level;
	static std::random_device rd;
	return rd() % (maxVal - minVal + 1) + minVal;
}