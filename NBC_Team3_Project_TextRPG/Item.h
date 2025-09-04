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
	Item(std::string name, int price);
	virtual ~Item() = default;

	std::string getName() const;
	int getPrice() const;
	virtual void use(Character* character) = 0;
};