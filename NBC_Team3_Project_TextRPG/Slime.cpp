#include "Slime.h"
using namespace std;

Slime::Slime(int playerLevel)
	: Monster("Slime", playerLevel)
{ 
	SetHealth();
	SetAttack();
}