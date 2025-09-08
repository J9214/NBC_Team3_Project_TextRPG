#pragma once

#include <vector>

class Item;
class Character;

class Shop
{
private:
	std::vector<Item*> availableItems;

public:
	Shop();
	~Shop();

	void DisplayItems() const;
	void BuyItem(int index, Character* player) const;
	void SellItem(int index, Character* player) const;
};