#include "GameManager.h"
#include <iostream>

using namespace std;

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	GameManager gameManager;
	gameManager.MainMenu();

	return 0;
}