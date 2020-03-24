#include <iostream>

using namespace std;

int main()
{
    int numberOfElementA, numberOfElementB;
    cin >> numberOfElementA;
    int arrA[numberOfElementA];
    for (int i = 0; i < numberOfElementA; i++) cin >> arrA[i];
    cin >> numberOfElementB;
    int arrB[numberOfElementB];
    for (int i = 0; i < numberOfElementB; i++) cin >> arrB[i];

    int total = 0;
    for (int i = 0; i < numberOfElementA; i++) {
        for (int j = 0; j < numberOfElementB; j++) {
            if (arrA[i] == arrB[j]) {
                total += 1;
                break;
            }
        }
    }
    if (total == numberOfElementA) cout << 1;
    else cout << 0;
}
