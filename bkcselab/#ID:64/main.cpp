#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 343, 23, 23};
	char element[] = "Element", value[] = "Value", total[] = "sum";
    int sum = 0;
    printf("%-15s%-15s\n", element, value);
    for (int i = 0; i < 5; i++) {
        printf("%-15d", i);
        printf("%-15d\n", arr[i]);
        sum += arr[i];
    }
    printf("%-15s%-15d", total, sum);
}
