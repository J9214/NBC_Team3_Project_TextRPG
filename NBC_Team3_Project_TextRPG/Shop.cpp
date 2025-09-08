#include <iostream>
#include "Shop.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Character.h"
using namespace std;

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

void Shop::DisplayItems() const
{
	cout << "========== 상점 ==========\n" << endl;

	size_t LoopCount = availableItems.size();

	for (size_t i = 0; i < LoopCount; ++i)
	{
		cout << i + 1 << ". " << availableItems[i]->GetName() << " " << availableItems[i]->GetPrice() << " Gold" << endl;
	}

	cout << "\n==========================\n" << endl;
}

void Shop::BuyItem(int index, Character* player) const
{
	// 예외 처리: 잘못된 번호 입력
	if (index < 0 || index > static_cast<int>(availableItems.size()))
	{
		cout << "잘못된 입력입니다." << endl;
		return;
	}

	// 예외 처리: 인벤토리가 꽉 찼는지 확인	
	if (player->GetInventorySize() >= player->GetMaxInventorySize())
	{
		cout << "인벤토리가 가득 찼습니다." << endl;
		return;
	}

	// 플레이어가 소지한 골드가 물건 가격 이상일 때 구매(체력 물약: 10 Gold, 공격력 강화: 15 Gold)
	Item* ItemToBuy = availableItems[index - 1]->Clone();
	
	if (player->GetGold() >= ItemToBuy->GetPrice())
	{
		player->SetGold(player->GetGold() - ItemToBuy->GetPrice());
		cout << ItemToBuy->GetName() << "을 구매하였습니다." << endl;

		// 인벤토리에 아이템 추가
		player->AddItem(ItemToBuy);
	}
	else
	{
		cout << "소지한 골드가 부족하여 아이템을 구매할 수 없습니다." << endl;
	}
}

void Shop::SellItem(int index, Character* player) const
{
	auto ItemToSell = player->GetItem(index - 1);

	if (ItemToSell != nullptr)
	{
		// 플레이어 인벤토리에서 판매할 물건 선택 후 원가 * 0.6 가격으로 판매
		player->SetGold(player->GetGold() + (ItemToSell->GetPrice() * 6) / 10);

		// 플레이어 인벤토리에서 판매한 아이템 삭제
		player->EraseItem(index - 1);
		cout << "판매 완료" << endl;
	}
}