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
	 displayInventory();
}

void Character::displayInventory()
{
	cout << "Inventory: " << endl;
	for (size_t i = 0; i < inventory.size(); i++) {
		cout << i + 1 << ". " << inventory[i]->getName() << endl;
	}
}

void Character::levelUp()
{
	while (level < maxLevel && experience >= 100) {
		level++;
		experience -= 100;
		maxHealth += level * 20;
		health = maxHealth;
		attack += level * 5;
	}
}

void Character::useItem(int index)
{	
	if (index < 0 || index >= inventory.size()) {
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return;
	}

	Item* item = inventory[index];
	if (item == nullptr) {
		std::cout << "아이템이 없습니다." << std::endl;
		return;
	}

	item->use(this);

	delete item;
	
	inventory.erase(inventory.begin() + index);
}

void Character::addItem(Item* item)
{
	if(inventory.size() >= maxInventorySize) {
		std::cout << "인벤토리가 가득 찼습니다." << std::endl;
		return;
	}
	inventory.push_back(item);
}

void Character::eraseItem(int index)
{
	if (index < 0 || index >= inventory.size()) {
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return;
	}
	Item* item = inventory[index];
	if (item == nullptr) {
		std::cout << "아이템이 없습니다." << std::endl;
		return;
	}
	delete item;
	inventory.erase(inventory.begin() + index);
}

string Character::getName()  const { return name; }
int Character::getHealth()  const { return health; }
int Character::getMaxHealth()  const { return maxHealth; }
int Character::getAttack()  const { return attack; }
int Character::getLevel()  const { return level; }
int Character::getMaxLevel()  const { return maxLevel; }
int Character::getExperience()  const { return experience; }
int Character::getMaxExperience()  const { return maxExperience; }
int Character::getGold()  const { return gold; }
int Character::getInventorySize()  const { return inventory.size(); }
int Character::getMaxInventorySize()  const { return maxInventorySize; }
Item* Character::getItem(int index)  const { 
	if (index < 0 || index >= inventory.size()) 
	{
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return nullptr;
	}
	return inventory[index]; 
}

void Character::setHealth(int health) {
	this->health = health;
	if (this->health < 0) this->health = 0;
	if (this->health > this->maxHealth) this->health = this->maxHealth;
}
void Character::setMaxHealth(int health) { this->maxHealth = health; }
void Character::setAttack(int attack) { this->attack = attack; }
void Character::setExperience(int experience) { this->experience = experience; }
void Character::setGold(int gold) { this->gold = gold; }
void Character::setLevel(int level) { this->level = level; }

Character::~Character() {
	for (auto item : inventory) {
		delete item;
	}
	inventory.clear();
}
