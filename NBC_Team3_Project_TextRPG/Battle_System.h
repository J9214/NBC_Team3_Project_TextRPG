#pragma once
#include <iostream>
#include <random>
#include "Monster.h"     
#include "Character.h" 

using namespace std;

class GameManger {

	
	Monster* generateMonster(int level);
	void battle(Character* player);

};