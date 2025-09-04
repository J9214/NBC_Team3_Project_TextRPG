#pragma once
//#include "BattleSystem.h"
#include "Shop.h"
class Item;
class Character;
class Monster;
class Inventory;
class BattleSystem;


class GameManager
{
private:
	Character* player;
	Monster* monster;
	Inventory* inventory;
	//BattleSystem battleSystem;
	Shop shop;

	Character* MakeCharacter();
	void ShopEnter();
	void ShowCharacterInfo();
	void ShowInventory();

	void Battle();
public:

	void MainMenu();

};