#pragma once
#include "Animal.h"
class Cow :
    protected Animal
{
private:

public:
    std::string makeSound() const;
};

