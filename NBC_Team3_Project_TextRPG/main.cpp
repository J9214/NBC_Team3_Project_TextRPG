#include <iostream>
#include "Monster.h"
#include "Goblin.h"

int main() {
    Monster* m = new Goblin(1);

    cout << "Name: " << m->getName() << endl;
    cout << "Health: " << m->getHealth() << endl;
    cout << "Attack: " << m->getAttack() << endl;

    m->takeDamage(10);
    cout << "Health after damage: " << m->getHealth() << endl;

    m = new Goblin(2);
    cout << "Name: " << m->getName() << endl;
    cout << "Health: " << m->getHealth() << endl;
    cout << "Attack: " << m->getAttack() << endl;

    delete m;
	return 0;
}
