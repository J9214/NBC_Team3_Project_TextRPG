#pragma once
#include <memory>
#include "Shop.h"
#include "BattleSystem.h"
#include "CharacterStatObserver.h"

class Character;
class Monster;

class GameManager
{
private:
	Character* player;
	Monster* gameMonster;
	Shop gameShop;
	BattleSystem gameBattleSystem;

	std::unique_ptr<CharacterStatObserver> playerStatsOb;

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