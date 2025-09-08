#include "Item.h"
using namespace std;

Item::Item() : name(""), price(0) {}

Item::Item(const Item& other) : name(other.name), price(other.price) {};

Item::Item(string name, int price) : name(name), price(price) {}

string Item::getName() const
{
	return name;
}

int Item::getPrice() const
{
	return price;
}