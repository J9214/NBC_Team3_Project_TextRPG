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
	int maxExperience = 100;
	int gold;
	int maxInventorySize = 10;

	// Item 
	std::vector<Item*> inventory;

public:
	Character(const Character&) = delete;
	Character& operator=(const Character&) = delete;

	Character(std::string name);
	static Character* getInstance(std::string name);

	std::string getName();
	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getLevel();
	int getMaxLevel();
	int getExperience();
	int getMaxExperience();
	int getGold();
	int getInventorySize();
	int getMaxInventorySize();
	Item* getItem(int index);

	void setHealth(int health);
	void setMaxHealth(int health);
	void setAttack(int attack);
	void setExperience(int experience);
	void setGold(int gold);
	void setLevel(int level) ;

	void displayStatus();
	void displayInventory();
	void levelUp();
	void useItem(int index);
	void addItem(Item* item);
	void eraseItem(int index);

	~Character();
};