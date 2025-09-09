#pragma once
#include "Event.h"

class Character;

class CharacterStatObserver : public GameObserver {
private:
	Character* targetPlayer;

public:

	CharacterStatObserver(Character* player) : 
		targetPlayer(player) 
	{
	}

	void OnNotify(GameEvent event, int value) override;
};