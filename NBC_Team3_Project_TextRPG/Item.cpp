#include "Item.h"
using namespace std;

Item::Item() {}

Item::Item(string name) : name(name) {}

string Item::getName() const
{
	return name;
}
