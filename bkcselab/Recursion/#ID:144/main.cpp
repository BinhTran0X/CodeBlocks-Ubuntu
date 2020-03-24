#include <iostream>

using namespace std;

void recursiveReverse(int* arr, int numberOfElements) {
    // TODO
    static int n = numberOfElements;
    if (numberOfElements != n/2) {
        swap(arr[numberOfElements - 1], arr[n - numberOfElements]);
        recursiveReverse(arr, numberOfElements - 1);
    }

}

int main()
{
    int arr[] = {1, 2, 4, 5, 7};
    recursiveReverse(arr, 5);
    for (int i = 0; i < 5; i++) {
        cout << arr[i];
    }
}
