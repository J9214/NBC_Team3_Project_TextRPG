#include "Battle_System.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Goblin.h"
#include "Orc.h"
#include "Slime.h"
#include "Troll.h"
#include "BossMonster.h"




Monster* BattleSystem::GenerateMonster(int level) {
	std::random_device rd;
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


bool BattleSystem::PlayerAttack(Monster* monster, Character* player) {   //플레이어가 몬스터 공격
	monster->TakeDamage(player->GetAttack());
	return monster->GetHealth() <= 0;
}
bool BattleSystem::MonsterAttack(Monster* monster, Character* player) { //몬스터가 플레이어 공격
	player->SetHealth(player->GetHealth() - monster->GetAttack());
	return player->GetHealth() <= 0;
}

void BattleSystem::Reward(Character* player) {  //보상
	std::random_device rd;
	int rd_getitem = rd() % 100;
	int rd_whichitem = rd() % 100;
	int rd_getgold = 10 + rd() % 11; //골드 10~20

	std::cout << "플레이어 " << player->GetName() << "은(는) 50의 경험치를 획득하였다." << std::endl;

	player->SetExperience(player->GetExperience() + 50);

	if (player->GetExperience() >= player->GetMaxExperience())
	{
		std::cout << "플레이어 " << player->GetName() << "은(는) 레벨업 하였다." << std::endl;
		player->levelUp();
		std::cout << "플레이어 " << player->GetName() << "의 현재 레벨: " << player->GetLevel() << std::endl;

	}
	std::cout << "플레이어 " << player->GetName() << "은(는) " << rd_getgold << "골드를 획득하였다." << std::endl;
	player->SetGold(player->GetGold() + rd_getgold);
	std::cout << "플레이어 " << player->GetName() << "의 현재 골드: " << player->GetGold() << std::endl;

	if (rd_whichitem < 50) {  //어떤 아이템 체력?공격?
		if (rd_getitem < 30) { //30퍼 확률 획득

			std::cout << "플레이어 " << player->GetName() << "은(는) 체력 포션을 획득하였다." << std::endl;
			player->AddItem(new HealthPotion());
		}
	}

	else {

		if (rd_getitem < 30) { //30퍼 확률 획득
			std::cout << "플레이어 " << player->GetName() << "은(는) 공격력 증가 포션을 획득하였다." << std::endl;
			player->AddItem(new AttackBoost());
		}
	}

}
void BattleSystem::UseItem(Character* player) {

	if (player->GetInventorySize() == 0)
	{
		return;
	}
	std::random_device rd;
	int rd_useitem = rd() % 100;
	if (rd_useitem < 30) { //아이템 사용 30확률  
		std::cout << "플레이어 " << player->GetName() << "은(는) " << player->GetItem(0)->GetName() << "을 사용했다." << std::endl;
		player->UseItem(0);  //인덱스0 아이템 사용
	}
	return;
}