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
	cout << "========== ���� ==========" << endl;

	size_t LoopCount = availableItems.size();

	for (size_t i = 0; i < LoopCount; ++i)
	{	
		cout << i + 1 << ". " << availableItems[i]->getName() << "N" << "Gold" << endl;
	}

	cout << "=========================" << endl;
}

void Shop::buyItem(int index, Character* player)
{
	// ���� ó��: �߸��� ��ȣ �Է�
	if (index <= 0 || index > static_cast<int>(availableItems.size()))
	{
		cout << "�߸��� �Է��Դϴ�." << endl;
		return;
	}

	// �÷��̾ ������ ��尡 ���� ���� �̻��� �� �Ǹ�(ü�� ����: 10 Gold, ���ݷ� ��ȭ: 15 Gold)
	if (player->getGold() >= availableItems[index]->getPrice())
	{
		player->setGold(player->getGold() - availableItems[index]->getPrice());
		cout << availableItems[index]->getName() << "��(��) �����Ͽ����ϴ�." << endl;
	}
	else
	{
		cout << "�������� ������ �� �����ϴ�." << endl;
	}
}

void Shop::sellItem(int index, Character* player)
{
	// �÷��̾� �κ��丮 ������ ��� ���
	
	// �÷��̾� �κ��丮���� �Ǹ��� ���� ����
	
	// ���� * 0.6 �������� �Ǹ�
	
	// �÷��̾� �κ��丮���� �Ǹ��� ������ ����
}