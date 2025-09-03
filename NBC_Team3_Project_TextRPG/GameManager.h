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
	void MakeCharacter();
	void ShopEnter();

public:

	void MainMenu();

};