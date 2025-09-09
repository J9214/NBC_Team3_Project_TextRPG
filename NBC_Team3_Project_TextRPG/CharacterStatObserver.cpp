#include "CharacterStatObserver.h"
#include "Character.h"

using namespace std;

void CharacterStatObserver::OnNotify(GameEvent event, int value)
{
	if (targetPlayer == nullptr) {
		return;
	}

	switch (event) {
	case GameEvent::NORMAL_MONSTER_KILLED:
		targetPlayer->AddKillCount(value);
		break;
	case GameEvent::GOLD_ACQUIRED:
		targetPlayer->AddTotalGold(value);
		break;
	case GameEvent::HEALTH_POTION_USED:
		targetPlayer->AddHealthPotionUsed(value);
		break;
	case GameEvent::ATTACK_BOOST_USED:
		targetPlayer->AddAttackBoostUsed(value);
		break;
	}
}
