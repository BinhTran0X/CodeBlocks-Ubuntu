#include <iostream>
using namespace std;

int main() {
	 int option;
	 cin >> option;
	 int arr[10][10];
	 for(int i = 0; i < 10; i++) {
	     for (int j = 0 ; j < 10; j++) {
	         cin >> arr[i][j];
	     }
	 }

	 if (option == 1) {
	     int result = arr[0][0];
	     for (int i = 1; i < 10; i++) {
	         if (arr[i][i] > result) result = arr[i][i];
	     }
	     cout << result;
	 }
	 if (option == 2) {
	     int result = arr[0][9];
	     for (int i = 1; i < 10; i++) {
	         if (arr[i][9-i] > result) result = arr[i][9-i];
	     }
	     cout << result;
	 }
}
