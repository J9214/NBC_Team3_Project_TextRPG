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
	bool SpawnBoss;
	Character* MakeCharacter();

	void ShopEnter();
	void ShowCharacterInfo();
	void PlayBattle();


public:
	GameManager() : Player(nullptr), GameMonster(nullptr), IsClear(false), SpawnBoss(false){}
	void PlayMainMenu();

};