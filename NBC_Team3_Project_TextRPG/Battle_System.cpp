#include "Battle_System.h"




Monster* GameManager::generateMonster(int level) {
	random_device rd;
	int rd_gen = rd() % 5;

	if (rd_gen == 0) {
		return new Goblin(level);
	}
	else if (rd_gen == 1) {
		return new Orc(level);
	}

	return nullptr;

}

void GameManager::battle(Character* player) {


}