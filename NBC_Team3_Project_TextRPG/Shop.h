#pragma once

#include <vector>

using namespace std;

class Item;
class Character;

class Shop
{
private:
	vector<Item*> availableItems;

public:
	Shop();
	~Shop();

	void displayItems() const;
	void buyItem(int index, Character* player) const;
	void sellItem(int index, Character* player) const;
};