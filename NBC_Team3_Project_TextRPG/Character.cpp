#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(std::string name)
{
	this->name = name;
	this->level = 1;
	this->health = 100;
	this->maxHealth = 100;
	this->attack = 10;
	this->experience = 0;
	this->gold = 0;
}

Character* Character::getInstance(std::string name)
{
	static Character instance(name);
	return &instance;
}

void Character::displayStatus()
{
	cout << "Name: " << name << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << health << "/" << maxHealth << endl;
	cout << "Attack: " << attack << endl;
	cout << "Experience: " << experience << endl;
	cout << "Gold: " << gold << endl;
	// cout << "Inventory: " << endl;
	// for (size_t i = 0; i < inventory.size(); i++) {
	// 	cout << i + 1 << ". " << inventory[i].getName() << endl;
}

void Character::levelUp()
{
	if (experience >= 100) {
		level++;
		experience = 0;
		health = maxHealth;
		attack += 5;
	}
}

void Character::useItem(int index)
{
	// Item item = inventory[index];
	// if (item.getType() == "health") {
	// 	health += item.getEffect();
	// 	if (health > maxHealth) health = maxHealth;
	// }
	// else if (item.getType() == "attack") {
	// 	attack += item.getEffect();
	// }
	// inventory.erase(inventory.begin() + index);
}
Character::~Character()
{
}