#include "TestCandidate.h"
#include "candidate.h"
#include <iostream>

TestCandidate::TestCandidate()
{
	std::cin >> this->size;
	this->dsts = new candidate[size];
}
TestCandidate::~TestCandidate()
{
	delete this->dsts;
}

void TestCandidate::Nhap()
{
	for (int i = 0; i < this->size; i++)
	{
		this->dsts[i].Nhap();
		std::cout << '\n';
	}
}
void TestCandidate::Xuat() const
{
	for (int i = 0; i < this->size; i++)
	{
		this->dsts[i].Xuat();
		std::cout << '\n';
	}
}

void TestCandidate::inDSTT()
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->dsts[i].getScoreSum() > 15)
		{
			this->dsts[i].Xuat();
			std::cout << '\n';
		}
	}
}