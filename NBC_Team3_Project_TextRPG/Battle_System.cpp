#include "Battle_System.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "BossMonster.h"


using namespace std;



Monster* BattleSystem::generateMonster(int level) {
	random_device rd;
	int rd_gen = rd() % 4;

	if (rd_gen == 0 && level < 10) {
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


bool BattleSystem::playerattack(Monster* monster, Character* player) {   //플레이어가 몬스터 공격
	monster->takeDamage(player->getAttack());
	if (monster->getHealth() == 0)
	{
		return true;
	}
	return false;
}
bool BattleSystem::monsterattack(Monster* monster, Character* player) { //몬스터가 플레이어 공격
	player->setHealth(player->getHealth() - monster->getAttack());
	if (player->getHealth() == 0)
	{
		return true;
	}
	return false;
}

void BattleSystem::reward(Character* player) {  //보상
	random_device rd;
	int rd_getitem = rd() % 100;
	int rd_whichitem = rd() % 100;
	int rd_getgold = 10 + rd() % 11; //골드 10~20

	cout << "플레이어는 50의 경험치를 획득하였다." << endl;

	player->setExperience(player->getExperience() + 50);

	if (player->getExperience() >= player->getMaxExperience())
	{
		cout << "플레이어는 레벨업 하였다." << endl;
		player->levelUp();
		cout << "플레이어의 현재 레벨: " << player->getLevel() << endl;

	}
	cout << "플레이어는 " << rd_getgold << "골드를 획득하였다." << endl;
	player->setGold(player->getGold() + rd_getgold);
	cout << "플레이어의 현재 골드: " << player->getGold() << endl;

	if (rd_whichitem < 50) {  //어떤 아이템 체력?공격?
		if (rd_getitem < 30) { //30퍼 확률 획득

			cout << "플레이어는 체력 포션을 획득하였다." << endl;
			player->addItem(new HealthPotion());
		}
	}

	else {

		if (rd_getitem < 30) { //30퍼 확률 획득
			cout << "플레이어는 공격력 증가 포션을 획득하였다." << endl;
			player->addItem(new AttackBoost());
		}
	}

}
void BattleSystem::useitem(Character* player) {

	if (player->getInventorySize() == 0)
	{
		return;
	}
	random_device rd;
	int rd_useitem = rd() % 100;
	if (rd_useitem < 30) { //아이템 사용 30확률  
		cout << "플레이어는 " << player->getItem(0)->getName() << "을 사용했다." << endl;
		player->useItem(0);  //인덱스0 아이템 사용
	}
	return;
}