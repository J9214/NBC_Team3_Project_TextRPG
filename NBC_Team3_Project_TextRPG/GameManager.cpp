#include <iostream>
#include "GameManager.h"

using namespace std;

void GameManager::MainMenu()
{
	player = MakeCharacter();
	while (true)
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
			Battle();
		}
		else if (choice == 2)
		{
			ShopEnter();
		}
		else if (choice == 3)
		{
			ShowCharacterInfo();
		}
		else if (choice == 4)
		{
			ShowInventory();
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
}
