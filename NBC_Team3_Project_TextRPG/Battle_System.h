#pragma once
#include <iostream>
#include <random>
#include "Monster.h"     
#include "Character.h" 

using namespace std;
class BattleSystem {
	Monster* generateMonster(int level);
	bool playerattack(Monster* monster, Character* player);
	void reward(Character* player);
	bool useitem(Character* player);
	bool monsterattack(Monster* monster, Character* player);
};


