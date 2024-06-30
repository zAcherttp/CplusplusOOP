#include "AnimalFarm.h"

int main()
{
    vector<Animal* > startingFarm =
    { new Cow(), new Cow(), new Sheep(), new Sheep(), new Goat(), new Goat() };

    AnimalFarm Farm(startingFarm);

    int option = 0;
    while (option != 4) {
        cout << "1 - next day.\n";
        cout << "2 - feed all.\n";
        cout << "3 - statistic.\n";
        cout << "4 - end.\n";
        
        cin >> option;
        switch (option)
        {
        case 1:
        {
            Farm.simulateDay();
            break;
        }
        case 2:
        {
            Farm.feedAll();
            break;
        }
        case 3:
        {
            Farm.printStatistic();
            Farm.getTotalMilk();
            break;
        }
        case 4:
        {
            return 0;
        }
        default:
            cout << "incorrect choice!\n";
        }
    }

    
}