#include "random.h"

random::random(int _start, int _end, int _seed)
{
    random_device rd;
    this->start = _start;
    this->end = _end;
    this->seed = rd();
}

random::~random()
{
}

int random::get() const
{
    mt19937 generator(this->seed);

    uniform_int_distribution<int> distribution(this->start, this->end);

    return distribution(generator);
}
