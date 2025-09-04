#include "GameManager.h"

using namespace std;

int main(void)
{
	GameManager* gameManager;
	gameManager = new GameManager();
	gameManager->MainMenu();
	gameManager->~GameManager();
	gameManager = nullptr;
	return 0;
}