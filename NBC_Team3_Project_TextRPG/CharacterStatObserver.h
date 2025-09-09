#pragma once
#include "Event.h"

class Character;

class CharacterStatObserver : public GameObserver {
private:
	Character* targetPlayer; // 통계를 업데이트할 대상 캐릭터를 가리키는 포인터

public:
	// 생성자에서 어떤 캐릭터의 통계를 추적할지 알려줍니다.
	CharacterStatObserver(Character* player) : 
		targetPlayer(player) 
	{
	}

	// IObserver의 인터페이스를 구현합니다.
	void OnNotify(GameEvent event, int value) override;
};