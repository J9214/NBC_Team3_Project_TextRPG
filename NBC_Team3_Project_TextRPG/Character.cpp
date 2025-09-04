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
		maxHealth += maxHealth + (level * 20);
		health = maxHealth;
		attack += attack + (level * 5);
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

void Character::visitShop()
{

}

string Character::getName() { return name; }
int Character::getHealth() { return health; }
int Character::getMaxHealth() { return maxHealth; }
int Character::getAttack() { return attack; }
int Character::getLevel() { return level; }
int Character::getMaxLevel() { return maxLevel; }
int Character::getExperience() { return experience; }
int Character::getMaxExperience() { return maxExperience; }
int Character::getGold() { return gold; }

void Character::setHealth(int health) { this->health = health; }
void Character::setMaxHealth(int health) { this->maxHealth = health; }
void Character::setAttack(int attack) { this->attack = attack; }
void Character::setExperience(int experience) { this->experience = experience; }
void Character::setGold(int goldg) { this->gold = gold; }
void Character::setLevel(int level) { this->level = level; }

Character::~Character()
{
}