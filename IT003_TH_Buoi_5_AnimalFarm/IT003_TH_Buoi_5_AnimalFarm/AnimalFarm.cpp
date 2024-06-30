#include "AnimalFarm.h"
#include "random.h"
#include <set>

int AnimalFarm::DayPassed = 0;

AnimalFarm::AnimalFarm(std::vector<Animal*> _animalList, vector<int> _totalMilkProductionAtDay)
    : AnimalList(_animalList), TotalMilkProductionAtDay(_totalMilkProductionAtDay) {}

void AnimalFarm::simulateDay() {
    cout << "Day " << DayPassed << " :\n";
    TotalMilkProductionAtDay.push_back(0);


    vector<Animal*> offspring;
    for (auto entity : AnimalList) {
        if ((entity->Gen * 5 - DayPassed) % 5 == 0) {
            entity->giveOffspring(offspring);
        }
        if ((entity->Gen * 3 - DayPassed) % 3 == 0) {
            entity->giveMilk();
        }
        else {
            entity->IndividualMilkProductionAtDay.push_back(0);
        }
        this->TotalMilkProductionAtDay[DayPassed] += entity->IndividualMilkProductionAtDay.back();
    }

    AnimalList.insert(AnimalList.end(), offspring.begin(), offspring.end());

    cout << "\tMilk (litres) produced: " << TotalMilkProductionAtDay[DayPassed] << "\n";
    cout << "\tFarm has expanded by " << offspring.size() << " cattles!\n";

    random hunger(30, 70);
    int amount = hunger.get();
    set<string> sounds;
    for (auto entity : AnimalList) {
        if (entity->HungerLevel <= 100 - amount) {
            entity->HungerLevel += amount;
        }
        else {
            entity->HungerLevel = 100;
            sounds.insert(entity->makeSound());
        }
    }
    cout << "\tHeard: ";
    for (const auto& sound : sounds) {
        cout << sound << " ";
    }
    cout << "\n";

    DayPassed++;
}

void AnimalFarm::printStatistic()
{
    int cow = 0;
    int sheep = 0;
    int goat = 0;

    for (auto entity : AnimalList) {
        string type = entity->Type;
        if (type == "Cow") cow++;
        else if (type == "Sheep") sheep++;
        else if (type == "Goat") goat++;
    }

    cout << "statistics:\n";
    cout << "\tCows: " << cow << "\n";
    cout << "\tSheep: " << sheep<< "\n";
    cout << "\tGoat: " << goat << "\n";
}

int AnimalFarm::getTotalMilk() const {
    int total = 0;
    for (const auto& each : TotalMilkProductionAtDay) {
        total += each;
    }
    return total;
}

void AnimalFarm::feedAll() {
    for (auto entity : AnimalList) {
        entity->eat();
    }
    cout << "\tFed all cattles!\n";
}
