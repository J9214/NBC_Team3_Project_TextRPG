#pragma once
//#include "BattleSystem.h"
#include "Shop.h"
#include "Battle_System.h"

class Character;
class Monster;

class GameManager
{
private:
	Character* player;
	Monster* monster;
	Shop shop;
	BattleSystem battleSystem;
	bool isClear;

	Character* MakeCharacter();

	void ShopEnter();
	void ShowCharacterInfo();
	void PlayBattle(bool spawnBoss);


public:
	GameManager() : player(nullptr), monster(nullptr), isClear(false) {}
	void PlayMainMenu();

};