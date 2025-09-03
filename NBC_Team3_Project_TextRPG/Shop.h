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

	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
};