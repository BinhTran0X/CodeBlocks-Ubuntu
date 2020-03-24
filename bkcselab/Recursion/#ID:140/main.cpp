#include <iostream>
#include <iomanip>
using namespace std;

void printLine(int arr[]) {
    static int i = 0;
    if (i != 5) {
        cout << setw(15) << left << i;
        cout << setw(15) << left << arr[i] << endl;
        i += 1;
        return printLine(arr);
    }
}

int findSum(int arr[]) {
    static int start = -1;
    if (start == 4) return 0;
    else {
        start += 1;
        return arr[start] + findSum(arr);
    }
}

void printOut(int arr[]){
    cout << setw(15) << left << "Element";
    cout << setw(15) << left << "Value" << endl;
    printLine(arr);
    int Sum = findSum(arr);
    cout << setw(15) << left << "sum";
    cout << setw(15) << left << Sum;
}

int main() {
	int arr[] = {1, 2, 3, 4, 5};
	printOut(arr);
}
