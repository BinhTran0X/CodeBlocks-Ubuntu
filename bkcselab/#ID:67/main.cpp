#include <iostream>

using namespace std;

int main()
{
    int key, numberOfElements;
    cin >> key;
    cin >> numberOfElements;
    int arr[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) cin >> arr[i];

    int length = 0;
    long long int total = 0;
    for (int i = 0; i < numberOfElements; i++) {
        if (arr[i] < key) {
            total += arr[i];
            length++;
        }
    }
    double result = total/length;
    if (length == 0) cout << 0;
    else printf("%.4f", result);
}
