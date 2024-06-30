#pragma once
#include "Animal.h"
using namespace std;

class Sheep :
	public Animal
{
public:
    static int Generation;
public:
    Sheep(string _type = "Sheep", int _gen = Generation) : Animal(_type, 0, 0, _gen) {}
    string makeSound() const override;
    void giveMilk() override;
    void giveOffspring(vector<Animal*>& farmSpace) override;
    void eat() override;
};