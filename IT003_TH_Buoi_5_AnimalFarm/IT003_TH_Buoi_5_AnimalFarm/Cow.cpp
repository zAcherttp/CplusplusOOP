#include "Cow.h"
#include "random.h"

int Cow::Generation = 1;

string Cow::makeSound() const
{
    return "Moo";
}

void Cow::giveMilk()
{
    random milk(0, 20);
    int ammount = milk.get();
    if (this->HungerLevel <= 30) this->HungerLevel += 30;
    else this->HungerLevel = 100;
    this->MilkProduction += ammount;
    this->IndividualMilkProductionAtDay.push_back(ammount);
}

void Cow::giveOffspring(vector<Animal*> &farmSpace)
{
    Cow::Generation++;
    random OffspringNum(1, 2);
    int childNum = OffspringNum.get();
    if (this->HungerLevel <= 30) this->HungerLevel += 30;
    else this->HungerLevel = 100;
    while (childNum--) {
        farmSpace.push_back(new Cow());
    }
}

void Cow::eat()
{
    random feed(20, 80);
    int ammount = feed.get();
    if (this->HungerLevel <= ammount) this->HungerLevel = 0;
    else this->HungerLevel -= ammount;
}
