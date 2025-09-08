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

	void displayItems() const;
	void buyItem(int index, Character* player) const;
	void sellItem(int index, Character* player) const;
};