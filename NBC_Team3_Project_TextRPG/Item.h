#pragma once
#include <string>

class Character;

class Item
{
private:
	std::string name;

public:
	Item(); // Basic Creation
	Item(std::string name);
	virtual ~Item() = default;

	std::string getName() const;
	virtual void use(Character* character) = 0;
};