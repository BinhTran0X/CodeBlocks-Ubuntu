#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    float number;
    int option;
    cin >> number;
    cin >> option;
    if (option == 1) cout << round(number);
    else if (option == 2) cout << floor(number);
    else if (option == 3) cout << ceil(number);
    else if (option == 4) {
        float result;
        result = round(number * 100)/100;
        cout << result;
    }
    return 0;
}
