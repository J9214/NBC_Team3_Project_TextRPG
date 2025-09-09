#pragma once
#include <vector>
#include "Monster.h"     
#include "Character.h" 
#include "Event.h"

class BattleSystem 
{
private:
	std::vector<GameObserver*> observers;
public:
	Monster* GenerateMonster(int level);
	bool PlayerAttack(Monster* monster, Character* player);
	bool MonsterAttack(Monster* monster, Character* player);
	void Reward(Character* player);
	void UseItem(Character* player);

	void AddObserver(GameObserver* observer);
	void RemoveObserver(GameObserver* observer);
	void Notify(GameEvent event, int value = 0);

};