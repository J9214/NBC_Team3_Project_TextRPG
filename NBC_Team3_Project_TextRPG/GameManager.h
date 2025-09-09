#pragma once
#include "Shop.h"
#include "BattleSystem.h"

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
	void ShowCharacterInfo() const;
	void PlayBattle();

public:
	GameManager();
	void PlayMainMenu();
};