#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    float a, b;
    cin >> a;
    cin >> b;
	float result;
	if (a == 0) {
        if (b == 0) cout << "+";
        else cout << "-";
    }
    else {
        if (b == 0) cout << "X = 0";
        else {
            result = -b/a;
            result = round(result*10000)/10000;
            cout << "X = " << result;
        }
    }
}
