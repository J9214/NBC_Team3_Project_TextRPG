#include <iostream>
#include "Character.h"
using namespace std;

Character::Character(std::string name)
{
	this->name = name;
	this->level = 1;
	this->maxHealth = 200; 
	this->health = this->maxHealth;
	this->attack = 30;
	this->experience = 0;
	this->gold = 0;
	this->inventory = {};
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
	 /*cout << "Inventory: " << endl;
	 for (size_t i = 0; i < inventory.size(); i++) {
	 cout << i + 1 << ". " << inventory[i]->getName() << endl;*/
}

void Character::levelUp()
{
	while (level < maxLevel && experience >= 100) {
		level++;
		experience -= 100;
		maxHealth += maxHealth + (level * 20);
		health = maxHealth;
		attack += attack + (level * 5);
	}
}

void Character::useItem(int index)
{	
	Item* item = nullptr;
	if (inventory[index] != nullptr) { item = inventory[index]; }

	item->use(this);
	delete item;
	/*if (item->getName() == "HealthPotion") { item->use(this); }
	else if (item->getName() == "AttackBoost") { item->use(this); }
		attack += item.getEffect();
	}*/
	inventory.erase(inventory.begin() + index);
}

void Character::visitShop()
{

}

int Character::getHealth() { return health; }
int Character::getMaxHealth() { return maxHealth; }
int Character::getAttack() { return attack; }
int Character::getLevel() { return level; }
int Character::getExperience() { return experience; }
int Character::getGold() { return gold; }

void Character::setHealth(int h) { this->health = h; }
void Character::setMaxHealth(int h) { this->maxHealth = h; }
void Character::getAttack(int a) { this->attack = a; }
void Character::setExperience(int exp) { this->experience = exp; }
void Character::setGold(int g) { this->gold = g; }
void Character::setLevel(int l) { this->level = l; }

Character::~Character()
{
}