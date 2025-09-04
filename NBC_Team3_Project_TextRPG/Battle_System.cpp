#include "Battle_System.h"
#include "iostream"
using namespace std;



Monster* BattleSystem::generateMonster(int level) {
	random_device rd;
	int rd_gen = rd() % 4;

	if (rd_gen == 0) {
		return new Goblin(level);
	}
	else if (rd_gen == 1) {
		return new Orc(level);
	}

	else if (rd_gen == 2) {
		return new Slime(level);
	}

	else if (rd_gen == 3) {
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
	int rd_itemget = rd() % 100;

	player->setExperience(50);
	player->setGold( player->getGold()+ 15 * player->getLevel());
	if (rd_itemget < 50)
	player->addItem(Item* item)
}
void BattleSystem::useitem(Character* player) {
	
	random_device rd;
	int rd_useitem = rd()%100; 
	if (rd_useitem < 30) { //아이템 사용확률
		player.useItem(0)  //첫번째 아이템사용 //작업중
	}
	
}

