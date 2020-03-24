#include <iostream>

using namespace std;

int main()
{
    int numberOfElements;
    cin >> numberOfElements;
    int arrA[numberOfElements], arrB[numberOfElements];
    for (int i = 0; i < numberOfElements ; i++) cin >> arrA[i];
    for (int i = 0; i < numberOfElements ; i++) cin >> arrB[i];

    char pos[] = "Pos";
    printf("%-10sOverlap", pos);
    for (int i = 0; i < numberOfElements ; i++) {
        if (arrA[i] == arrB[i]) {
            cout << endl;
            printf("%-10d%d", i, arrA[i]);
            i += 1;

            for(; i < numberOfElements; i++) {
                if (arrA[i] == arrB[i]) {
                    cout << " " << arrA[i];
                }
                else break;
            }
        }
    }
}
