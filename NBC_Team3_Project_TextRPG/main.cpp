#include "GameManager.h"
#include <iostream>

using namespace std;

int main(void)
{
	GameManager* gameManager;
	gameManager = new GameManager();
	gameManager->PlayMainMenu();
	gameManager->~GameManager();
	gameManager = nullptr;
	return 0;
}