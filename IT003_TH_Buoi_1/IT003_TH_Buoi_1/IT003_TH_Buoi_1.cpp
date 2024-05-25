// IT003_TH_Buoi_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhanSo.h"
#include "complex.h"
#include "candidate.h"
#include "TestCandidate.h"
using namespace std;

int main()
{
    int option;
    cout << "1. lop phan so." << '\n';
    cout << "2. lop so phuc." << '\n';
    cout << "3. lop thi sinh va kiem tra thi sinh." << '\n';
    cout << "chon cau (1, 2, 3)?: ";
    cin >> option;
    switch (option)
    {
    case 1:
        PhanSo A, B;
        A.Nhap();
        B.Nhap();
        cout << "tong = "; (A + B).rutGon().Xuat(); cout << '\n';
        cout << "hieu = "; (A - B).rutGon().Xuat(); cout << '\n';
        cout << "tich = "; (A * B).rutGon().Xuat(); cout << '\n';
        cout << "thuong = "; (A / B).rutGon().Xuat(); cout << '\n';
    }
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
