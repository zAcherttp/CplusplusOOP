#include "Animal.h"

Animal::Animal(string _type, int _hunger, int _milk, int _gen)
{
	this->Type = _type;
	this->HungerLevel = _hunger;
	this->MilkProduction = _milk;
	this->IndividualMilkProductionAtDay = {};
	this->Gen = _gen;
}

Animal::~Animal()
{
}

std::string Animal::makeSound() const
{
	return "...";
}

void Animal::giveMilk()
{
}

void Animal::giveOffspring(vector<Animal*>& farmSpace)
{
}

void Animal::eat()
{
}
