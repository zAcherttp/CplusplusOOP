#include <vector>
#include <iostream>
#include "NhanVienSX.h"
#include "NhanVienVP.h"

using namespace std;

int main()
{
    int n;
    vector<NhanVien*> DSNhanVien;
    cout << "nhap so nhan vien: ";
    cin >> n;
    for (int i{}; i < n; i++)
    {
        int base_salary = 0;
        int product_num = 0;
        NhanVienSX temp;
        cin >> temp;
        cout << "nhap luong co ban: ";
        cin >> base_salary;
        cout << "nhap so san pham: ";
        cin >> product_num;
        temp.setBaseSalary(base_salary);
        temp.setProductNum(product_num);
        DSNhanVien.push_back(new NhanVienSX(temp));
    }

    cout << "-------------------------" << '\n';
    for (int i{}; i < n; i++)
    {
        cout << *DSNhanVien[i];
        cout << "-------------------------" << '\n';
    }
}