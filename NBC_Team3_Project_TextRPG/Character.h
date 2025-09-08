#pragma once
#include <string>
#include <vector>
#include "Item.h"

class Character
{
private:
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
	static Character* GetInstance(std::string name);

	std::string GetName() const;
	int GetHealth() const;
	int GetMaxHealth() const;
	int GetAttack() const;
	int GetLevel() const;
	int GetMaxLevel() const;
	int GetExperience() const;
	int GetMaxExperience() const;
	int GetGold() const;
	int GetInventorySize() const;
	int GetMaxInventorySize() const;
	Item* GetItem(int index) const;

	void SetHealth(int health);
	void SetMaxHealth(int health);
	void SetAttack(int attack);
	void SetExperience(int experience);
	void SetGold(int gold);
	void SetLevel(int level) ;

	void DisplayStatus();
	void DisplayInventory();
	void LevelUp();
	void UseItem(int index);
	void AddItem(Item* item);
	void EraseItem(int index);

	~Character();
};