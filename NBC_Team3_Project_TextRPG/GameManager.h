#pragma once

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

	void Battle();
	Character* MakeCharacter();
	void ShopEnter();
	void ShowCharacterInfo();
	void ShowInventory();

public:

	void MainMenu();

};