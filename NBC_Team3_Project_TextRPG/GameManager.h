#pragma once
//손우참 
#include "Shop.h"
#include "Battle_System.h"

class Character;
class Monster;

class GameManager
{
private:
	Character* Player;
	Monster* GameMonster;
	Shop GameShop;
	BattleSystem GameBattleSystem;
	bool IsClear;

	Character* MakeCharacter();

	void ShopEnter();
	void ShowCharacterInfo();
	void PlayBattle(bool spawnBoss);


public:
	GameManager() : Player(nullptr), GameMonster(nullptr), IsClear(false) {}
	void PlayMainMenu();

};