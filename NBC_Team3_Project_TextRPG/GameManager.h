#pragma once
//#include "BattleSystem.h"
#include "Shop.h"

class Character;
class BattleSystem;
/*
	Monster* monster;
	//BattleSystem battleSystem;
	Shop shop;
*/

class GameManager
{
private:
	Character* player;
	Character* MakeCharacter();
	//void ShopEnter();
	void ShowCharacterInfo();
	//void ShowInventory();

	//void Battle();
public:
	GameManager() : player(nullptr) {}
	void MainMenu();

};