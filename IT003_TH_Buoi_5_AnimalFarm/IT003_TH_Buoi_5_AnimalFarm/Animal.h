#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Animal
{
public:
	string Type;
	int HungerLevel;
	int MilkProduction;
	vector<int> IndividualMilkProductionAtDay;
	int Gen;
public:
	Animal(string _type = "", int _hunger = 0, int _milk = 0, int _gen = 1);
	~Animal();

	virtual string makeSound() const;
	virtual void giveMilk();
	virtual void giveOffspring(vector<Animal*> &farmSpace);
	virtual void eat();
};

