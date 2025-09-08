#include "Troll.h"
using namespace std;

Troll::Troll(int playerLevel)
	: Monster("Troll", playerLevel)
{ 
	SetHealth();
	SetAttack();
}