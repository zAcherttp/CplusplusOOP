// IT003_TH_Buoi_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "IntSet.h"

using namespace std;

int main()
{
	int* list = new int[3];
	list[0] = 1;
	list[1] = 2;
	list[2] = 2;
	IntSet s1, s2(list, 3), s3;
	cin >> s1 >> s2;
	s3 = s1 + s2;
	s3 = s1 - s2;
	cout << "cout << s3: ";
	cout << s3;
	cout << "cout << s3[0]: ";
	cout << s3[0];
	cout << "cout << (s1 == s2): ";
	cout << (s1 == s2);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
