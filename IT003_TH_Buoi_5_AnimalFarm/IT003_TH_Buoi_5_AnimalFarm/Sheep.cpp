#include "Sheep.h"
#include "random.h"

int Sheep::Generation = 1;

string Sheep::makeSound() const
{
    return "Baa";
}

void Sheep::giveMilk()
{
    random milk(0, 5);
    int ammount = milk.get();
    if (this->HungerLevel <= 30) this->HungerLevel += 30;
    else this->HungerLevel = 100;
    this->MilkProduction += ammount;
    this->IndividualMilkProductionAtDay.push_back(ammount);
}

void Sheep::giveOffspring(vector<Animal*>& farmSpace)
{
    Sheep::Generation++;
    random OffspringNum(1, 2);
    int childNum = OffspringNum.get();
    if (this->HungerLevel <= 30) this->HungerLevel += 30;
    else this->HungerLevel = 100;
    while (childNum--) {
        farmSpace.push_back(new Sheep());
    }
}

void Sheep::eat()
{
    random feed(20, 80);
    int ammount = feed.get();
    if (this->HungerLevel <= ammount) this->HungerLevel = 0;
    else this->HungerLevel -= ammount;
}
