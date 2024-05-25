#include "Animal.h"

Animal::Animal(std::string _type, int _hunger, int _milk)
{
	this->Type = _type;
	this->HungerLevel = _hunger;
	this->MilkProduction = _milk;
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

void Animal::giveOffspring()
{
}

void Animal::eat() const
{
}
