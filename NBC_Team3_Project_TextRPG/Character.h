#pragma once
#include <string>
#include <vector>
//#include "Item.h"

class Character {
private:
	std::string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;

	// Item 정의 된 후 추가
	// vector<Item> invetory;

public:
	Character(std::string name);
	static Character* getInstance(std::string name);

	void displayStatus();
	void levelUp();
	void useItem(int index);
};