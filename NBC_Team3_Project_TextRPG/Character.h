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

	int getHealth();
	int getMaxHealth();
	int getAttack();
	int getLevel();
	int getExperience();
	int getGold();
	
	void setHealth(int h);
	void setMaxHealth(int h);
	void getAttack(int a);
	void setExperience(int exp);
	void setGold(int g);
	void setLevel(int l) ;

	void displayStatus();
	void levelUp();
	void useItem(int index);
	void visitShop();

	~Character();
};