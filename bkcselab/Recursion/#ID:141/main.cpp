#include <iostream>

using namespace std;

int recursiveMax(int* arr, int numberOfElements) {
    // TODO
//    static int maximum = arr[0];
//    if (numberOfElements == 1) {
//        return maximum;
//    }
//    else {
//        maximum = max(arr[numberOfElements - 1], maximum);
//        return recursiveMax(arr, numberOfElements - 1);
//    }

    if (numberOfElements == 1) {
        return arr[0];
    }
    else {
        return max(arr[numberOfElements - 1], recursiveMax(arr, numberOfElements - 1));
    }

}

int main()
{
    int a[] = {1, 2, 3, 18, 5};
    int maximum = recursiveMax(a, 5);
    cout << maximum;
}
