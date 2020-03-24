#include <iostream>

using namespace std;

int main()
{
    int option;
    cin >> option;
    int squareMatrixSize;
    cin >> squareMatrixSize;

    int** arr = new int* [squareMatrixSize];
    for (int i = 0 ; i < squareMatrixSize; i++) {
        arr[i] = new int [squareMatrixSize];
        for (int j = 0 ; j < squareMatrixSize; j++) {
            cin >> arr[i][j];
        }
    }

    long int res = 0;
    if (option == 1) {
        for (int i = 0; i < squareMatrixSize; i++) res += arr[i][i];
        cout << res;
    }
    else if (option == 2) {
        for (int i = 0; i < squareMatrixSize - 1; i++) {
            for (int j = i+1; j < squareMatrixSize; j++) {
                res += arr[i][j];
            }
        }
        cout << res;
    }
    else if (option == 3) {
        for (int i = 1; i < squareMatrixSize; i++) {
            for (int j = 0; j < i; j++) {
                res += arr[i][j];
            }
        }
        cout << res;
    }
}

