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
	
	bool isClear;

	Character* MakeCharacter();
	Monster* generatedMonster(int level, bool isBoss);

	void ShopEnter();
	void ShowCharacterInfo();
	void PlayBattle(bool spawnBoss);
	void TestBattle(bool spawnBoss);

public:
	GameManager() : player(nullptr), monster(nullptr), isClear(false) {}
	void PlayMainMenu();

};