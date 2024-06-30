#pragma once
#include <random>
using namespace std;

class random
{
public:
	int start;
	int end;
	int seed;

	random(int _start = 0, int _end = 1, int _seed = 0);
	~random();

	int get() const;
};

