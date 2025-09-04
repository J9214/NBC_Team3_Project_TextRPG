#include <iostream>
#include <string>
#include "GameManager.h"
#include "Character.h"

using namespace std;

Character* GameManager::MakeCharacter()
{
	string name;
	while (player == nullptr)
	{
		cout << "플레이어의 이름을 입력하세요." << endl;

		getline(cin, name);

		if (cin.fail() || name == "")
		{
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}
		break;	
	}
	return player->getInstance(name);

}
/*
void GameManager::ShopEnter()
{
	while (true) 
	{
		system("cls");


		cout << "상점에 오신걸 환영합니다." << endl;
		cout << "구매 가능한 아이템: " << endl;
		//ShopList(); 
		//vector<item>* list = Shop->list();
		cout << "Health Potion (체력 +50): 10 골드" << endl;
		cout << "Attack Boost (공격력 +10): 15 골드" << endl;

		//Inventory -> List();
		cout << "4. 인벤토리" << endl;

		cout << "5. 종료" << endl;
		cout << "구매할 아이템 번호를 선택하세요: ";

		int choice;
		cin >> choice;

		if (cin.fail())
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		cout << "\n---------------------------\n" << endl;

		if (choice == 1)
		{

			//Shop->ByItem;
		}
		else if (choice == 2)
		{
		}
		else if (choice == 3)
		{
		}
		else if (choice == 4)
		{
		}
		else if (choice == 5)
		{
			cout << "상점에서 나갑니다..." << endl;
			break;
		}
		else
		{
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
		}

		cout << "\n---------------------------\n" << endl;
	}



}
*/


void GameManager::ShowCharacterInfo()
{

	cout << "플레이어 캐릭터 정보" << endl;
	cout << "플레이어 이름: " << player->getName() << endl;
	cout << "레벨: " << player->getLevel() << " / 10" << endl;
	cout << "체력: " << player->getHealth() << " / " << player->getMaxHealth() << endl;
	cout << "공격력: " << player->getAttack() << endl;
	cout << "경험치: " << player->getExperience() << " / 100" << endl;
	
	return;
}

/*void GameManager::ShowInventory()
{

	int index = 1;
	if (Inventory->Items.empty()) 
	{
		cout << "아이템이 없습니다." << endl;
		cout << endl;
		cout << "골드: " << Inventory.getGold() << endl;
		system("pause");

		return;
	}

	cout << "--- [ " << 인벤토리 목록 << " ] ---" << endl;

	for (const auto& recipe : Inventory->GetItems())
	{
		cout << index << "번 아이템 이름: " << recipe->getName();
		++index;
	}
	cout << endl;
	cout << "골드: " << Inventory.getGold() << endl;

	return;
}
*/

/*void GameManager::Battle()
{

	cout << "플레이어 체력: " << player->getHP() << " | 공격력: " << player->getAttack() << endl;
	cout << "몬스터 체력: " << monster->getHP() << " | 공격력: " << monster->getAttack() << endl;
	cout << "전투 개시!" <<endl;
	cout << endl;

	while (player->getHP() != 0 && monster->getHP() != 0)
	{
		cout << "플레이어의 턴!" << endl;
		if(	balltesystem.useitem(inventory, player) == true)
		{
			cout << "플레이어는 아이템을 사용했다." << endl;
		}

		cout << "플레이어는 몬스터에게 " << player->getAttack() << " 데미지를 주었다" << endl;
		if(	battlesystem.attack(player, monster) == true)
		{
			cout << "몬스터의 남은 체력: " << monster->getHP() << endl;
			cout << "몬스터는 사망하였다." << endl;
			cout << "플레이어 승리! " << endl;
			battlesystem.reward(player);
			return;
		}

		cout << "몬스터의 남은 체력: " << monster->getHP() << endl;
		cout << "몬스터의 턴!" << endl;

		cout << "몬스터는 플레이어에게 " << monster->getAttack() << " 데미지를 주었다" << endl;
		if(	battlesystem.attack(monster, player) == true)
		{
			cout << "플레이어의 남은 체력: " << player->getHP() << endl;
			cout << "플레이어는 사망하였다." << endl;
			cout << "몬스터의 승리! " << endl;
			return;
		}
		cout << "플레이어의 남은 체력: " << player->getHP() << endl;

	}
}
*/
void GameManager::MainMenu()
{

	if (player == nullptr)
	{
		player = MakeCharacter();
	}
	/*
	if(monster == nullptr)
{
	// monster = MonsterGeneration();
}
	*/
	while (/*player->getHP() != 0*/ true)
	{
		cout << "텍스트 기반 RPG 게임" << endl;
		cout << "1. 전투하기" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 내 정보" << endl;
		cout << "4. 인벤토리" << endl;

		cout << "5. 종료" << endl;
		cout << "선택: ";

		int choice;
		cin >> choice;

		if (cin.fail()) 
		{
			cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			continue;
		}

		cout << "\n---------------------------\n" << endl;
		if (choice == 1)
		{
			//Battle();
		}
		else if (choice == 2)
		{
			//ShopEnter();
		}
		if (choice == 3)
		{
			ShowCharacterInfo();
		}
		else if (choice == 4)
		{
			//ShowInventory();
		}
		else if (choice == 5)
		{
			cout << "게임을 종료합니다..." << endl;
			break;
		}
		else
		{
			cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
		}

		cout << "\n---------------------------\n" << endl;

	}
	return;
}


