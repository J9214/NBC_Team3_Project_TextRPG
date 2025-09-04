#pragma once
//#include "BattleSystem.h"
#include "Shop.h"

class Character;
class BattleSystem;
/*
	Monster* monster;
	//BattleSystem battleSystem;
	
*/

class GameManager
{
private:
	Character* player;
	Character* MakeCharacter();

	Shop shop;

	void ShopEnter();
	void ShowCharacterInfo();
	//void ShowInventory();

	void PlayBattle();
public:
	GameManager() : player(nullptr) {}
	void MainMenu();

};