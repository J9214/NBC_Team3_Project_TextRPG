#include "Battle_System.h"
#include "iostream"
using namespace std;



Monster* BattleSystem::generateMonster(int level) {
	random_device rd;
	int rd_gen = rd() % 4;

	if (rd_gen == 0&&level<10) {
		return new Goblin(level);
	}
	else if (rd_gen == 1 && level < 10) {
		return new Orc(level);
	}

	else if (rd_gen == 2 && level < 10) {
		return new Slime(level);
	}

	else if (rd_gen == 3 && level < 10) {
		return new Troll(level);
	}
	else if (level == 10) {
		return new BossMonster(level);
	}
	else {
		return nullptr;
	}

}


void BattleSystem::playerattack(Monster* monster, Character* player) {
	monster->takeDamage(player->getAttack());
}
void BattleSystem::monsterattack(Monster* monster, Character* player) {
	player->setHealth(player->getHealth() - monster->getAttack());
}

void BattleSystem::reward(Character* player) {
	random_device rd;
	int rd_getitem = rd() % 100;
	int rd_whichitem = rd() % 100;
	int rd_getgold = 10+rd()%11
	player->setExperience(50);
	player->setGold( player->getGold()+ rd_goldget);
	
	
	if (rd_whichitem < 50) {
		if (rd_getitem < 30) {
			player->addItem(Item * item);
		}
	}

	else {
		if (rd_getitem < 30) {
			player->addItem(Item * item);
		}
	}
	
}
void BattleSystem::useitem(Character* player) {
	
	random_device rd;
	int rd_useitem = rd()%100; 
	if (rd_useitem < 30) { //아이템 사용확률
		player.useItem(0)  //인덱스0 아이템 사용
	}
	
}

