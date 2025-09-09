#include <iostream>
#include <random>
#include "BattleSystem.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "BossMonster.h"
using namespace std;

Monster* BattleSystem::GenerateMonster(int level) 
{
	random_device rd;
	int rdGen = rd() % 4;

	if (rdGen == 0 && level < 10) 
	{
		return new Goblin(level);
	}
	else if (rdGen == 1 && level < 10) 
	{
		return new Orc(level);
	}

	else if (rdGen == 2 && level < 10) 
	{
		return new Slime(level);
	}

	else if (rdGen == 3 && level < 10) 
	{
		return new Troll(level);
	}
	else if (level == 10) 
	{
		return new BossMonster(level);
	}
	else 
	{
		return nullptr;
	}
}

bool BattleSystem::PlayerAttack(Monster* monster, Character* player) 
{   
	monster->TakeDamage(player->GetAttack());
	return monster->GetHealth() <= 0;
}

bool BattleSystem::MonsterAttack(Monster* monster, Character* player) 
{
	player->SetHealth(player->GetHealth() - monster->GetAttack());
	return player->GetHealth() <= 0;
}

void BattleSystem::Reward(Character* player) 
{  
	random_device rd;
	int rdGetItem = rd() % 100;
	int rdWhichItem = rd() % 100;
	int rdGetGold = 10 + rd() % 11; 
	cout << "=================== 전투 보상 =================== " << endl;
	cout << endl;
	cout << "플레이어 " << player->GetName() << "은(는) 50의 경험치를 획득하였다." << endl;

	player->SetExperience(player->GetExperience() + 50);

	if (player->GetExperience() >= player->GetMaxExperience())
	{
		cout << "플레이어 " << player->GetName() << "은(는) 레벨업 하였다." << endl;
		player->LevelUp();
		cout << "플레이어 " << player->GetName() << "의 현재 레벨: " << player->GetLevel() << endl;

	}
	cout << "플레이어 " << player->GetName() << "은(는) " << rdGetGold << "골드를 획득하였다." << endl;
	player->SetGold(player->GetGold() + rdGetGold);
	cout << "플레이어 " << player->GetName() << "의 현재 골드: " << player->GetGold() << endl;

	if (rdWhichItem < 50) 
	{  
		if (rdGetItem < 30) 
		{

			cout << "플레이어 " << player->GetName() << "은(는) 체력 포션을 획득하였다." << endl;
			player->AddItem(new HealthPotion());
		}
	}

	else 
	{

		if (rdGetItem < 30) 
		{ 
			cout << "플레이어 " << player->GetName() << "은(는) 공격력 증가 포션을 획득하였다." << endl;
			player->AddItem(new AttackBoost());
		}
	}
}

void BattleSystem::UseItem(Character* player) 
{
	if (player->GetInventorySize() == 0)
	{
		return;
	}

	random_device rd;
	int rdUseItem = rd() % 100;
	if (rdUseItem < 30) 
	{  
		cout << "플레이어 " << player->GetName() << "은(는) " << player->GetItem(0)->GetName() << "을 사용했다." << endl;
		player->UseItem(0);  //인덱스0 아이템 사용
	}

	return;
}