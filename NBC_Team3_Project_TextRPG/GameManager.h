#pragma once
//#include "BattleSystem.h"
#include "Shop.h"

class Character;
class BattleSystem;
class Monster;
/*

	//BattleSystem battleSystem;
	
*/

class GameManager
{
private:
	Character* player;
	Monster* monster;
	Shop shop;

	Character* MakeCharacter();



	void ShopEnter();
	void ShowCharacterInfo();
	//void ShowInventory();

	void PlayBattle();
public:
	GameManager() : player(nullptr), monster(nullptr) {}
	void PlayMainMenu();

};