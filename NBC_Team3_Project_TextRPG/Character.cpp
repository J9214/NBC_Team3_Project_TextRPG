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

Character* Character::GetInstance(std::string name)
{
	static Character instance(name);
	return &instance;
}

void Character::DisplayStatus()
{
	 cout << "Name: " << name << endl;
	 cout << "Level: " << level << endl;
	 cout << "Health: " << health << "/" << maxHealth << endl;
	 cout << "Attack: " << attack << endl;
	 cout << "Experience: " << experience << endl;
	 cout << "Gold: " << gold << endl;
	 DisplayInventory();
}

void Character::DisplayInventory()
{
	cout << "Inventory: " << endl;
	for (size_t i = 0; i < inventory.size(); i++) 
	{
		cout << i + 1 << ". " << inventory[i]->GetName() << endl;
	}
}

void Character::LevelUp()
{
	while (level < maxLevel && experience >= 100) 
	{
		level++;
		experience -= 100;
		maxHealth += level * 20;
		health = maxHealth;
		attack += level * 5;
	}
}

void Character::UseItem(int index)
{	
	if (index < 0 || index >= inventory.size()) 
	{
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return;
	}

	Item* item = inventory[index];
	if (item == nullptr) 
	{
		std::cout << "아이템이 없습니다." << std::endl;
		return;
	}

	item->Use(this);

	delete item;
	
	inventory.erase(inventory.begin() + index);
}

void Character::AddItem(Item* item)
{
	if(inventory.size() >= maxInventorySize) 
	{
		std::cout << "인벤토리가 가득 찼습니다." << std::endl;
		return;
	}
	inventory.push_back(item);
}

void Character::EraseItem(int index)
{
	if (index < 0 || index >= inventory.size()) 
	{
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return;
	}
	Item* item = inventory[index];
	if (item == nullptr) 
	{
		std::cout << "아이템이 없습니다." << std::endl;
		return;
	}
	delete item;
	inventory.erase(inventory.begin() + index);
}

string Character::GetName() const 
{ 
	return name; 
}
int Character::GetHealth() const 
{ 
	return health; 
}
int Character::GetMaxHealth() const 
{ 
	return maxHealth; 
}
int Character::GetAttack() const 
{ 
	return attack; 
}
int Character::GetLevel() const 
{ 
	return level; 
}
int Character::GetMaxLevel() const 
{ 
	return maxLevel; 
}
int Character::GetExperience() const 
{ 
	return experience; 
}
int Character::GetMaxExperience() const 
{ 
	return maxExperience; 
}
int Character::GetGold() const 
{ 
	return gold; 
}
int Character::GetInventorySize() const 
{ 
	return inventory.size(); 
}
int Character::GetMaxInventorySize() const 
{ 
	return maxInventorySize; 
}
Item* Character::GetItem(int index) const 
{ 
	if (index < 0 || index >= inventory.size()) 
	{
		std::cout << "잘못된 인덱스입니다." << std::endl;
		return nullptr;
	}
	return inventory[index]; 
}

void Character::SetHealth(int health) 
{
	this->health = health;
	if (this->health < 0)
	{
		this->health = 0;
	}
	if (this->health > this->maxHealth)
	{
		this->health = this->maxHealth;
	}
}
void Character::SetMaxHealth(int health) 
{ 
	this->maxHealth = health; 
}
void Character::SetAttack(int attack) 
{ 
	this->attack = attack; 
}
void Character::SetExperience(int experience) 
{ 
	this->experience = experience; 
}
void Character::SetGold(int gold) 
{ 
	this->gold = gold; 
}
void Character::SetLevel(int level) 
{ 
	this->level = level; 
}

Character::~Character() 
{
	for (auto item : inventory) 
	{
		delete item;
	}
	inventory.clear();
}
