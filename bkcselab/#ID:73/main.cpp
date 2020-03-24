#include <iostream>

using namespace std;

int main()
{
    int numberOfElements;
    cin >> numberOfElements;
    int arr[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) cin >>arr[i];
    int res = 0;
    if (arr[0]%2 == 0 && arr[1]%2 == 0) res += 1;
    if (arr[numberOfElements-1]%2 == 0 && arr[numberOfElements-2]%2 == 0) res += 1;
    for (int i = 1; i < numberOfElements - 1; i++){
        if (arr[i]%2 == 0) {
            if(arr[i-1]%2 == 0 || arr[i+1]%2 == 0) res += 1;
        }
    }
    cout << res;

}
