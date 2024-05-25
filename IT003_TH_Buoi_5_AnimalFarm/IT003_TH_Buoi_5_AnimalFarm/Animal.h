#pragma once
#include <iostream>
#include <string>
#include <vector>

class Animal
{
private:
	std::string Type;
	int HungerLevel;
	int MilkProduction;
	std::vector<int> IndividualMilkProductionAtDay;
	int Generation;
public:
	Animal(std::string _type = "", int _hunger, int _milk);
	~Animal();
	virtual std::string makeSound() const;
	static void giveMilk();
	static void giveOffspring();
	void eat() const;
};

