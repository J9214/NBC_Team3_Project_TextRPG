#include "Battle_System.h"
#include "HealthPotion.h"
#include "AttackBoost.h"

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


bool BattleSystem::playerattack(Monster* monster, Character* player) {   //�÷��̾ ���� ����
	if (monster->getHealth != 0)
	{
		monster->takeDamage(player->getAttack());
		return true;
	}
	else {
		return false;
	}
}
bool BattleSystem::monsterattack(Monster* monster, Character* player) { //���Ͱ� �÷��̾� ����
	if (player->getHealth != 0) {
		player->setHealth(player->getHealth() - monster->getAttack());
		return true;
	}
	else {
		return false;
	}
}

void BattleSystem::reward(Character* player) {  //����
	random_device rd;
	int rd_getitem = rd() % 100; 
	int rd_whichitem = rd() % 100;
	int rd_getgold = 10 + rd() % 11; //��� 10~20
	player->setExperience(50);
	player->setGold( player->getGold()+ rd_goldget);
	
	
	if (rd_whichitem < 50) {  //� ������ ü��?����?
		if (rd_getitem < 30) { //30�� Ȯ�� ȹ��
			HealthPotion* healthpotion = new HealthPotion();
			player->addItem(healthpotion);
		}
	}

	else {
		
		if (rd_getitem < 30) { //30�� Ȯ�� ȹ��
			AttackBoost* attackboost = new AttackBoost();
			player->addItem(attackboost);
		}
	}
	
}
bool BattleSystem::useitem(Character* player) {
	
	random_device rd;
	int rd_useitem = rd()%100; 
	if (rd_useitem < 30) { //������ ��� 30Ȯ��  
		player->useItem(0);  //�ε���0 ������ ���
		return true;
	}
	
		return false;
	
	
}

