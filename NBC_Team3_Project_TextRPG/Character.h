#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Character {
private:
	//static Character* Instance();

	std::string name;
	int maxLevel = 10;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;

	// Item 
	std::vector<Item*> inventory;

public:
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	Character(std::string name);
	static Character* getInstance(std::string name);

	int getHealth() { return health; }
	int getMaxHealth() { return maxHealth; }
	int getAttack() { return attack; }
	int getLevel() { return level; }
	int getExperience() { return experience; }
	int getGold() { return gold; }
	
	void setHealth(int h) { health = h; }	
	void setMaxHealth(int h) { maxHealth = h; }
	void getAttack(int a) { attack = a; }
	void setExperience(int exp) { experience = exp; }
	void setGold(int g) { gold = g; }
	void setLevel(int l) { level = l; }

	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();

	~Character();
};