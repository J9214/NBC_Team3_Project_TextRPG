#pragma once

enum class GameEvent
{
	NORMAL_MONSTER_KILLED,
	ELITE_MONSTER_KILLED,
	BOSS_MONSTER_KILLED,
	GOLD_ACQUIRED,
	HEALTH_POTION_USED,
	ATTACK_BOOST_USED
};

class GameObserver
{
public:
	virtual ~GameObserver()
	{
	}
	virtual void OnNotify(GameEvent event, int value = 0) = 0;
};