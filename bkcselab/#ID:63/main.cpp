#include <iostream>

using namespace std;

int main() {
    int n, result = 0;
    cin >> n;
    while (n > 0) {
        result = result*10 + n%10;
        n /= 10;
    }
    cout << result;
}
