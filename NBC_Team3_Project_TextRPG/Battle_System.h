#pragma once
#include <iostream>
#include <random>
#include "Monster.h"     
#include "Character.h" 

using namespace std;
class BattleSystem {
	Monster* generateMonster(int level);
	void playerattack(Monster* monster, Character* player);
	void reward(Character* player);
	void useitem(Character* player);
	void monsterattack(Monster* monster, Character* player);
};


