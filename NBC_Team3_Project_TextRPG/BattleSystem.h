#pragma once
#include "Monster.h"     
#include "Character.h" 

class BattleSystem 
{
public:
	Monster* GenerateMonster(int level);
	bool PlayerAttack(Monster* monster, Character* player);
	bool MonsterAttack(Monster* monster, Character* player);
	void Reward(Character* player);
	void UseItem(Character* player);
};