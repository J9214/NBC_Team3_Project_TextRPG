#pragma once
#include <iostream>
#include <random>
#include "Monster.h"
#include "Character.h"

class Goblin : public Monster {
private:
	string name;
	int health;
	int attack;
public:
    Goblin(int level) {
        name = "Goblin";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dist(0, 100);

        double chance = dist(gen);

        if (chance < 30) {
            level = level - 1;
        }
        else if (chance < 70) {
            level = level;
        }
        else {
            level = level + 1;
        }

        health = level_control * 20 + rand() % (level_control * 30 - level_control * 20 + 1);
        attack = level_control * 5 + rand() % (level_control * 10 - level_control * 5 + 1);
    }
};