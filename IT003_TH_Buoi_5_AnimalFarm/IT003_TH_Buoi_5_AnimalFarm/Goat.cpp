#include "Goat.h"
#include "random.h"

int Goat::Generation = 1;

string Goat::makeSound() const
{
    return "Maa";
}

void Goat::giveMilk()
{
    random milk(0, 10);
    int ammount = milk.get();
    if (this->HungerLevel <= 30) this->HungerLevel += 30;
    else this->HungerLevel = 100;
    this->MilkProduction += ammount;
    this->IndividualMilkProductionAtDay.push_back(ammount);
}

void Goat::giveOffspring(vector<Animal*>& farmSpace)
{
    Goat::Generation++;
    random OffspringNum(1, 5);
    int childNum = OffspringNum.get();
    if (this->HungerLevel <= 50) this->HungerLevel += 50;
    else this->HungerLevel = 100;
    while (childNum--) {
        farmSpace.push_back(new Goat());
    }
}

void Goat::eat()
{
    random feed(20, 80);
    int ammount = feed.get();
    if (this->HungerLevel <= ammount) this->HungerLevel = 0;
    else this->HungerLevel -= ammount;
}
