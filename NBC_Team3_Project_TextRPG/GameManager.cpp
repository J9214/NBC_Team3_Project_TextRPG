#include <iostream>
#include <string>
#include <Windows.h>
#include "GameManager.h"
#include "Character.h"
#include "Goblin.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

using namespace std;
Character* GameManager::MakeCharacter()
{
	string Name;

	while (Player == nullptr)
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

	return Character::getInstance(Name);
}


void GameManager::ShopEnter()
{
	while (true) 
	{
		system("cls");
		cout << "상점에 오신걸 환영합니다." << endl;

		GameShop.displayItems();
		
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

				GameShop.displayItems();
				Player->displayInventory();

				cout << endl;
				cout << "현재 보유한 골드: " << Player->getGold() << "G" << endl;
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

				GameShop.buyItem((Index), Player);

				system("pause");
			}
		}
		else if (ShopChoice == 2)
		{
			int Index = 0;

			while(Index != -1)
			{
				system("cls");
				Player->displayInventory(); 

				cout << endl;
				cout << "현재 보유한 골드: " << Player->getGold() << "G" << endl;
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

				GameShop.sellItem(Index, Player);

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

void GameManager::ShowCharacterInfo()
{
	Player->displayStatus();

	return;
}

void GameManager::PlayBattle(bool spawnBoss)
{
	cout << "플레이어 " << Player->getName() << " 체력: " << Player->getHealth() << " | 공격력: " << Player->getAttack() << endl;
	cout << "몬스터 " << GameMonster->getName() << " 체력: " << GameMonster->getHealth() << " | 공격력: " << GameMonster->getAttack() << endl;
	cout << "전투 개시!" <<endl;
	cout << endl;

	while (Player->getHealth() != 0 && GameMonster->getHealth() != 0)
	{
		cout << "플레이어 " << Player->getName() << "의 턴!" << endl;
		GameBattleSystem.useitem(Player);

		cout << "플레이어 " << Player->getName() << "은(는) 몬스터 " << GameMonster->getName() << "에게 " << Player->getAttack() << " 데미지를 주었다" << endl;
		
		if(GameBattleSystem.playerattack(GameMonster, Player) == true)
		{
			cout << "몬스터 " << GameMonster->getName() << "의 남은 체력: " << GameMonster->getHealth() << endl;
			cout << "몬스터 " << GameMonster->getName() << "은(는) 사망하였다." << endl;
			cout << endl;
			cout << "플레이어 " << Player->getName() << " 승리! " << endl;
			cout << endl;

			if(spawnBoss == true)
			{
				IsClear = true;
				return;
			}

			GameBattleSystem.reward(Player);
			cout << endl;

			system("pause");
			return;
		}

		cout << "몬스터 " << GameMonster->getName() << "의 남은 체력: " << GameMonster->getHealth() << endl;
		cout << endl;
		cout << "몬스터 " << GameMonster->getName() << "의 턴!" << endl;

		cout << "몬스터 " << GameMonster->getName() << "은(는) 플레이어 " << Player->getName() << "에게 " << GameMonster->getAttack() << " 데미지를 주었다" << endl;

		if(	GameBattleSystem.monsterattack(GameMonster, Player) == true)
		{
			cout << "플레이어 " << Player->getName() << "의 남은 체력: " << Player->getHealth() << endl;
			cout << "플레이어 " << Player->getName() << "은(는) 사망하였다." << endl;
			cout << endl;
			cout << "몬스터 " << GameMonster->getName() << "의 승리! " << endl;
			return;
		}

		cout << "플레이어 " << Player->getName() << "의 남은 체력: " << Player->getHealth() << endl;
		cout << endl;
	}
	
	return;
}

void GameManager::PlayMainMenu()
{
	bool spawnBoss = false;

	if (Player == nullptr)
	{
		Player = MakeCharacter();
	}

	system("cls");

	while (Player->getHealth() != 0 && IsClear == false)
	{
		system("cls");

		cout << endl;
		
		if(Player->getLevel() == Player->getMaxLevel())
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
			
			if (GameMonster == nullptr)
			{
				GameMonster = GameBattleSystem.generateMonster(Player->getLevel());
			}

			PlayBattle(spawnBoss);

			delete GameMonster;
			GameMonster = nullptr;

			cout << endl;

			continue;
		}
		else if (choice == 2)
		{
			ShopEnter();
			cout << endl;

			continue;
		}
		else if (choice == 3)
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

	if (IsClear == true)
	{
		cout << "축하합니다. " << Player->getName() << "은 보스를 처치하고 게임을 클리어했습니다!" << endl;
	}
	else
	{
		cout << Player->getName() << ", 당신은 몬스터와 처절한 전투 끝에 사망하고 말았습니다." << endl;
	}
	return;
}


