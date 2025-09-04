#include <iostream>
#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Character.h"

Shop::Shop()
{
	availableItems.push_back(new HealthPotion);
	availableItems.push_back(new AttackBoost);
}

Shop::~Shop()
{
	size_t LoopCount = availableItems.size();

	for (size_t i = 0; i < LoopCount; ++i)
	{
		delete availableItems[i];
	}

	availableItems.clear();
}

void Shop::displayItems()
{
	cout << "========== 상점 ==========" << endl;

	size_t LoopCount = availableItems.size();

	for (size_t i = 0; i < LoopCount; ++i)
	{
		cout << i + 1 << ". " << availableItems[i]->getName() << "N" << "Gold" << endl;
	}

	cout << "=========================" << endl;
}

void Shop::buyItem(int index, Character* player)
{
	// 예외 처리: 잘못된 번호 입력
	if (index <= 0 || index >= static_cast<int>(availableItems.size()))
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	// 플레이어가 소지한 골드가 물건 가격 이상일 때 판매(체력 물약: 10 Gold, 공격력 강화: 15 Gold)
	// ...
}

void Shop::sellItem(int index, Character* player)
{
	// 플레이어 인벤토리 아이템 목록 출력

	// 플레이어 인벤토리에서 판매할 물건 선택

	// 원가 * 0.6 가격으로 판매

	// 플레이어 인벤토리에서 판매한 아이템 삭제
}