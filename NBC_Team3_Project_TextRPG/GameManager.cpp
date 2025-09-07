#include <iostream>
#include <string>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Goblin.h"
#include "HealthPotion.h"
#include "AttackBoost.h"


Character* GameManager::MakeCharacter()
{
	string name;
	while (player == nullptr)
	{
		cout << "플레이어의 이름을 입력하세요." << endl;
		cout << "이름: ";
		getline(cin, name);

		if (cin.fail() || name.find_first_not_of(" \t") == string::npos)
		{
			cout << "log make player : 잘못된 입력입니다. 다시 입력해주세요." << endl;
			cin.clear();
			cout << endl;
			continue;
		}
		break;	
	}

	return Character::getInstance(name);
}


void GameManager::ShopEnter()
{
	while (true) 
	{
		system("cls");
		cout << "상점에 오신걸 환영합니다." << endl;

		shop.displayItems();
		

		cout << "1. 아이템을 구매합니다." << endl;
		cout << "2. 아이템을 판매합니다." << endl;
		cout << "3. 상점에서 나갑니다." << endl;
		cout << "선택: ";
		int shopChoice;
		cin >> shopChoice;

		if (cin.fail())
		{
			cout << "log manager shopcoice : 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		cout << "\n---------------------------\n" << endl;

		if (shopChoice == 1)
		{
			int index = 0;
			while(index != -1)
			{
				system("cls");
				shop.displayItems();
				player->displayInventory();

				cout << endl;
				cout << "현재 보유한 골드: " << player->getGold() << "G" << endl;
				cout << endl;
				cout << "구매할 아이템 번호를 선택하세요: " << endl;
				cout << "구매를 원치 않으신 경우 0을 입력하세요." << endl;
				cout << "선택: ";
				cin >> index;

				if (cin.fail())
				{
					cout << "log manager shop buy: 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				if (index == 0)
				{
					break;
				}
				cout << endl;

				shop.buyItem((index), player);

				system("pause");

			}

		}
		else if (shopChoice == 2)
		{
			int index = 0;
			while(index != -1)
			{
				system("cls");
				player->displayInventory();
				cout << endl;
				cout << "현재 보유한 골드: " << player->getGold() << "G" << endl;
				cout << endl;
				cout << "판매할 아이템 번호를 선택하세요: " << endl;
				cout << "판매를 원치 않으신 경우 0을 입력하세요." << endl;
				cout << "선택: ";
				cin >> index;

				if (cin.fail())
				{
					cout << "log manager shop sell: 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
					cin.clear();
					cin.ignore(10000, '\n');
					continue;
				}
				if (index == 0)
				{
					break;
				}
				shop.sellItem(index, player);
				system("pause");
			}
		}
		else if (shopChoice == 3)
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

void GameManager::ShowCharacterInfo()
{
	player->displayStatus();
	/*
	cout << "플레이어 캐릭터 정보" << endl;
	cout << "플레이어 이름: " << player->getName() << endl;
	cout << "레벨: " << player->getLevel() << " / " << player->getMaxLevel() << endl;
	cout << "체력: " << player->getHealth() << " / " << player->getMaxHealth() << endl;
	cout << "공격력: " << player->getAttack() << endl;
	cout << "경험치: " << player->getExperience() << " / " << player->getMaxExperience() << endl;
	*/
	
	return;
}

void GameManager::PlayBattle(bool spawnBoss)
{
	cout << "플레이어 " << player->getName() << " 체력: " << player->getHealth() << " | 공격력: " << player->getAttack() << endl;
	cout << "몬스터 " << monster->getName() << " 체력: " << monster->getHealth() << " | 공격력: " << monster->getAttack() << endl;
	cout << "전투 개시!" <<endl;
	cout << endl;

	while (player->getHealth() != 0 && monster->getHealth() != 0)
	{
		cout << "플레이어의 턴!" << endl;
		battleSystem.useitem(player);

		cout << "플레이어는 몬스터에게 " << player->getAttack() << " 데미지를 주었다" << endl;
		if(battleSystem.playerattack(monster, player) == true)
		{
			cout << "몬스터의 남은 체력: " << monster->getHealth() << endl;
			cout << "몬스터는 사망하였다." << endl;
			cout << endl;
			cout << "플레이어 승리! " << endl;
			cout << endl;
			if(spawnBoss == true)
			{
				isClear = true;
				return;
			}
			battleSystem.reward(player);
			cout << endl;

			system("pause");
			return;
		}

		cout << "몬스터의 남은 체력: " << monster->getHealth() << endl;
		cout << endl;
		cout << "몬스터의 턴!" << endl;

		cout << "몬스터는 플레이어에게 " << monster->getAttack() << " 데미지를 주었다" << endl;

		if(	battleSystem.monsterattack(monster, player) == true)
		{
			cout << "플레이어의 남은 체력: " << player->getHealth() << endl;
			cout << "플레이어는 사망하였다." << endl;
			cout << endl;
			cout << "몬스터의 승리! " << endl;
			return;
		}
		cout << "플레이어의 남은 체력: " << player->getHealth() << endl;
		cout << endl;
	}
	
	return;
}

void GameManager::PlayMainMenu()
{
	bool spawnBoss = false;

	if (player == nullptr)
	{
		player = MakeCharacter();
	}
	system("cls");

	while (player->getHealth() != 0 && isClear == false)
	{
		system("cls");

		cout << endl;
		if(player->getLevel() == player->getMaxLevel())
		{
			spawnBoss = true;
		}

		cout << "텍스트 기반 RPG 게임" << endl;
		cout << "1. 전투하기" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 내 정보" << endl;

		cout << "4. 게임 종료" << endl;
		cout << "선택: ";

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cout << "log play choice : 잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		cout << "\n---------------------------\n" << endl;
	
		if (choice == 1)
		{
			system("cls");
			if (monster == nullptr)
			{
				monster = battleSystem.generateMonster(player->getLevel());
			}
			PlayBattle(spawnBoss);
			delete monster;
			monster = nullptr;
			cout << endl;

			continue;
		}
		else if (choice == 2)
		{

			ShopEnter();
			cout << endl;

			continue;
		}
		if (choice == 3)
		{
			system("cls");
			ShowCharacterInfo();
			cout << endl;
			system("pause");
			continue;
		}
		else if (choice == 4)
		{
			system("cls");
			cout << "게임을 종료합니다..." << endl;
			break;
		}
		else
		{
			cout << "log play main : 잘못된 선택입니다. 다시 시도하세요." << endl;
		}

		cout << "\n---------------------------\n" << endl;

	}

	if (isClear == true)
	{
		cout << "축하합니다. " << player->getName() << "은 보스를 처치하고 게임을 클리어했습니다!" << endl;
	}
	else
	{
		cout << player->getName() << ", 당신은 몬스터와 처절한 전투 끝에 사망하고 말았습니다." << endl;

	}
	return;
}


