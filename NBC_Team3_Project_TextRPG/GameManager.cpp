#include <iostream>
#include <string>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Sound.h"

using namespace std;

GameManager::GameManager()
	: player(nullptr),
	gameMonster(nullptr),
	isClear(false),
	spawnBoss(false)
{
}

Character* GameManager::MakeCharacter()
{
	string Name;

	while (player == nullptr)
	{
		cout << "플레이어의 이름을 입력하세요." << endl;
		cout << "이름: ";

		getline(cin, Name);

		if (cin.fail() || Name.find_first_not_of(" \t") == string::npos)
		{
			cout << "log make player : 잘못된 입력입니다. 다시 입력해주세요." << endl;
			cin.clear();
			cout << endl;

			continue;
		}

		break;	
	}
	
	return Character::GetInstance(Name);
}

void GameManager::ShopEnter()
{
	while (true) 
	{
		system("cls");
		cout << "상점에 오신걸 환영합니다." << endl;

		gameShop.DisplayItems();
		
		cout << "1. 아이템을 구매합니다." << endl;
		cout << "2. 아이템을 판매합니다." << endl;
		cout << "3. 상점에서 나갑니다." << endl;
		cout << "선택: ";

		int ShopChoice;
		cin >> ShopChoice;

		if (cin.fail())
		{
			cout << "log manager shopcoice : 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');

			continue;
		}

		cout << "\n---------------------------\n" << endl;

		if (ShopChoice == 1)
		{
			int Index = 0;
			while(Index != -1)
			{
				system("cls");

				gameShop.DisplayItems();
				player->DisplayInventory();

				cout << endl;
				cout << "현재 보유한 골드: " << player->GetGold() << "G" << endl;
				cout << endl;

				cout << "구매할 아이템 번호를 선택하세요: " << endl;
				cout << "구매를 원치 않으신 경우 0을 입력하세요." << endl;
				cout << "선택: ";

				cin >> Index;

				if (cin.fail())
				{
					cout << "log manager shop buy: 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				if (Index == 0)
				{
					break;
				}

				cout << endl;

				gameShop.BuyItem((Index), player);

				system("pause");
			}
		}
		else if (ShopChoice == 2)
		{
			int Index = 0;

			while(Index != -1)
			{
				system("cls");
				player->DisplayInventory(); 

				cout << endl;
				cout << "현재 보유한 골드: " << player->GetGold() << "G" << endl;
				cout << endl;

				cout << "판매할 아이템 번호를 선택하세요: " << endl;
				cout << "판매를 원치 않으신 경우 0을 입력하세요." << endl;
				cout << "선택: ";

				cin >> Index;

				if (cin.fail())
				{
					cout << "log manager shop sell: 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
					cin.clear();
					cin.ignore(10000, '\n');

					continue;
				}

				if (Index == 0)
				{
					break;
				}

				gameShop.SellItem(Index, player);

				system("pause");
			}
		}
		else if (ShopChoice == 3)
		{
			cout << "상점에서 나갑니다..." << endl;

			break;
		}
		else
		{
			cout << "log shop: 잘못된 선택입니다. 다시 시도하세요." << endl;
		}

		cout << "\n---------------------------\n" << endl;
	}

	return;
}

void GameManager::ShowCharacterInfo() const
{
	player->DisplayStatus();
	cout << endl;
	cout << "Killed Monster: " << player->GetKillCount() << endl;
	cout << "Total Gold: " << player->GetTotalGold() << endl;
	cout << "Use Health Potion: " << player->GetHealthPotionUsed() << endl;
	cout << "Use Attack Boost: " << player->GetAttackBoostUsed() << endl;
	return;
}

void GameManager::PlayBattle()
{
	cout << "플레이어 " << player->GetName() << " 체력: " << player->GetHealth() << " | 공격력: " << player->GetAttack() << endl;
	cout << "몬스터 " << gameMonster->GetName() << " 체력: " << gameMonster->GetHealth() << " | 공격력: " << gameMonster->GetAttack() << endl;
	cout << "전투 개시!" <<endl;
	cout << endl;

	while (player->GetHealth() != 0 && gameMonster->GetHealth() != 0)
	{
		cout << "플레이어 " << player->GetName() << "의 턴!" << endl;
		gameBattleSystem.UseItem(player);

		cout << "플레이어 " << player->GetName() << "은(는) 몬스터 " << gameMonster->GetName() << "에게 " << player->GetAttack() << " 데미지를 주었다" << endl;
		
		if(gameBattleSystem.PlayerAttack(gameMonster, player) == true)
		{
			cout << "몬스터 " << gameMonster->GetName() << "의 남은 체력: " << gameMonster->GetHealth() << endl;
			cout << "몬스터 " << gameMonster->GetName() << "은(는) 사망하였다." << endl;
			cout << endl;
			cout << "플레이어 " << player->GetName() << " 승리! " << endl;
			cout << endl;

			if(spawnBoss == true)
			{
				isClear = true;
				return;
			}

			gameBattleSystem.Reward(player);
			cout << endl;

			system("pause");
			return;
		}

		cout << "몬스터 " << gameMonster->GetName() << "의 남은 체력: " << gameMonster->GetHealth() << endl;
		cout << endl;
		cout << "몬스터 " << gameMonster->GetName() << "의 턴!" << endl;

		cout << "몬스터 " << gameMonster->GetName() << "은(는) 플레이어 " << player->GetName() << "에게 " << gameMonster->GetAttack() << " 데미지를 주었다" << endl;

		if(	gameBattleSystem.MonsterAttack(gameMonster, player) == true)
		{
			cout << "플레이어 " << player->GetName() << "의 남은 체력: " << player->GetHealth() << endl;
			cout << "플레이어 " << player->GetName() << "은(는) 사망하였다." << endl;
			cout << endl;
			cout << "몬스터 " << gameMonster->GetName() << "의 승리! " << endl;
			return;
		}

		cout << "플레이어 " << player->GetName() << "의 남은 체력: " << player->GetHealth() << endl;
		cout << endl;
	}
	
	return;
}

void GameManager::PlayMainMenu()
{

	if (player == nullptr)
	{
		player = MakeCharacter();
	}
	playerStatsOb = make_unique<CharacterStatObserver>(player);
	gameBattleSystem.AddObserver(playerStatsOb.get());

	SoundManager::GetInstance()->PlayBGM("src/music/main.mp3");

	system("cls");

	while (player->GetHealth() != 0 && isClear == false)
	{
		system("cls");

		cout << endl;
		
		if(player->GetLevel() == player->GetMaxLevel())
		{
			spawnBoss = true;
		}

		cout << "텍스트 기반 RPG 게임" << endl;
		cout << "1. 전투하기" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 내 정보" << endl;
		cout << "4. 게임 종료" << endl;

		cout << "선택: ";

		int Choice;
		cin >> Choice;

		if (cin.fail())
		{
			cout << "log play choice : 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		cout << "\n---------------------------\n" << endl;
	
		if (Choice == 1)
		{
			system("cls");
			
			if (gameMonster == nullptr)
			{
				gameMonster = gameBattleSystem.GenerateMonster(player->GetLevel());
			}

			PlayBattle();

			delete gameMonster;
			gameMonster = nullptr;

			cout << endl;

			continue;
		}
		else if (Choice == 2)
		{
			ShopEnter();
			cout << endl;

			continue;
		}
		else if (Choice == 3)
		{
			system("cls");
			ShowCharacterInfo();

			cout << endl;
			system("pause");

			continue;
		}
		else if (Choice == 4)
		{
			system("cls");
			cout << "게임을 종료합니다..." << endl;
			SoundManager::GetInstance()->StopBGM();

			return;
		}
		else
		{
			cout << "log play main : 잘못된 선택입니다. 다시 시도하세요." << endl;
		}

		cout << "\n---------------------------\n" << endl;
	}

	if (isClear == true)
	{
		cout << "축하합니다. " << player->GetName() << "은 보스를 처치하고 게임을 클리어했습니다!" << endl;
	}
	else
	{
		cout << player->GetName() << ", 당신은 몬스터와 처절한 전투 끝에 사망하고 말았습니다." << endl;
	}
	SoundManager::GetInstance()->StopBGM();

	return;
}