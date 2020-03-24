#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int numberOfElements;
    cin >> numberOfElements;
    int arr[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        int x;
        cin >> x;
        arr[i] = fabs(x);
    }
    int res = 0;
    if (arr[0] < arr[1]) res += 1;
    if (arr[numberOfElements-1] > arr[numberOfElements-2]) res += 1;
    for (int i = 1; i < numberOfElements - 1; i++){
        if((arr[i] - arr[i-1])*(arr[i] - arr[i+1]) < 0) res += 1;
    }
    cout << res;
}
