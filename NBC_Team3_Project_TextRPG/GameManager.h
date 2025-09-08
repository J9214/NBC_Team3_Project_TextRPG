#pragma once
//손우참 
#include "Shop.h"
#include "Battle_System.h"

class Character;
class Monster;

class GameManager
{
private:
	Character* player;
	Monster* gameMonster;
	Shop gameShop;
	BattleSystem gameBattleSystem;
	bool isClear;
	bool spawnBoss;
	Character* MakeCharacter();

	void ShopEnter();
	void ShowCharacterInfo();
	void PlayBattle();


public:
	GameManager() : player(nullptr), gameMonster(nullptr), isClear(false), spawnBoss(false){}
	void PlayMainMenu();

};