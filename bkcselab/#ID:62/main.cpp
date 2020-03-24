#include <iostream>

using namespace std;

int main() {
    int n, start = 1;
    cin >> n;
    for (int i = start + 1; i <= n - 1; i++) {
        if (n%i == 0) {
            start = i;
            cout << start;
            break;
        }
    }
    for (int i = start + 1; i <= n - 1; i++) {
        if (n%i == 0) {
            cout << " " << i;
        }
    }
}
