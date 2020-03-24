#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

bool isLeapYear(int year) {
    if (year%400 == 0) return true;
    else {
        if (year%100 == 0) return false;
        else {
            if (year%4 == 0) return true;
            else return false;
        }
    }
}

int main() {
    int day, month, year;
    cin >> day;
    cin >> month;
    cin >> year;
    bool feb = isLeapYear(year);
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        if (day >= 1 && day <= 9) cout << year << 0 << month << 0 << day;
        else if (day >= 10 && day <= 31)  cout << year << 0 << month << day;
        else cout << -1;
        break;

        case 10:
        case 12:
        if (day >= 1 && day <= 9) cout << year << month << 0 << day;
        else if (day >= 10 && day <= 31)  cout << year << month << day;
        else cout << -1;
        break;

        case 4:
        case 6:
        case 9:
        if (day >= 1 && day <= 9) cout << year << 0 << month << 0 << day;
        else if (day >= 10 && day <= 30)  cout << year << 0 << month << day;
        else cout << -1;
        break;

        case 11:
        if (day >= 1 && day <= 9) cout << year << month << 0 << day;
        else if (day >= 10 && day <= 30)  cout << year << month << day;
        else cout << -1;
        break;

        case 2:
        if (feb) {
            if (day >= 1 && day <= 9) cout << year << 0 << month << 0 << day;
            else if (day >= 10 && day <= 29)  cout << year << 0 << month << day;
            else cout << -1;
        }
        else {
            if (day >= 1 && day <= 9) cout << year << 0 << month << 0 << day;
            else if (day >= 10 && day <= 28)  cout << year << 0 << month << day;
            else cout << -1;
        }
        break;
        default: cout << -1;
    }
}
