#pragma once
#include "Animal.h"
#include "Cow.h"
#include "Sheep.h"
#include "Goat.h"
class AnimalFarm
{
public:
	vector<Animal*> AnimalList;
	vector<int> TotalMilkProductionAtDay;
	static int DayPassed;
public:
	AnimalFarm(vector<Animal*> _animalList = {}, vector<int> _totalMilkProductionAtDay = {});

	void simulateDay();
	void printStatistic();
	int getTotalMilk() const;
	void feedAll();
};

