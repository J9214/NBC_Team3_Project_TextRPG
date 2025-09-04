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
	
	void setHealth(int health);
	void setMaxHealth(int health);
	void setAttack(int attack);
	void setExperience(int experience);
	void setGold(int gold);
	void setLevel(int level) ;

	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();

	~Character();
};