#pragma once
#include <string>

class Character;

class Item
{
private:
	std::string name;
	int price;

public:
	Item();
	Item(const Item& other);
	Item(std::string name, int price);
	virtual ~Item() = default;

	std::string GetName() const;
	int GetPrice() const;
	virtual void Use(Character* character) = 0;
	virtual Item* Clone() = 0;
};