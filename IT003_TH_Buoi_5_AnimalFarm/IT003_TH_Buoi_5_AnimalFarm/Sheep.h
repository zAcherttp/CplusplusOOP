#pragma once
#include "Animal.h"
class Sheep :
    protected Animal
{
private:

public:
    std::string makeSound() const;
};

