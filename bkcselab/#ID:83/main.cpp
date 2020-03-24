#include <iostream>
using namespace std;

int main() {
	int numberOfRow, numberOfColumn;
	cin >> numberOfRow >> numberOfColumn;

	char** arr = new char* [numberOfRow];
	for(int i = 0; i < numberOfRow; i++) {
	    arr[i] = new char [numberOfColumn];
	    for(int j = 0; j < numberOfColumn; j++) {
	        cin >> arr[i][j];
	    }
	}

	int* P[4];
	for(int i = 0; i < 4; i++) {
	    P[i] = new int [numberOfColumn];
	    for(int j = 0; j < numberOfColumn; j++) {
	        P[i][j] = 0;
	    }
	}

	char* C = new char [numberOfColumn];

	for(int i = 0; i < numberOfRow; i++) {
	    for(int j = 0; j < numberOfColumn; j++) {
	        if (arr[i][j] == 'A') P[0][j] += 1;
	        else if (arr[i][j] == 'T') P[1][j] += 1;
	        else if (arr[i][j] == 'G') P[2][j] += 1;
	        else if (arr[i][j] == 'C') P[3][j] += 1;
	    }
	}

	char pos[] = "ATGC";

	int* maximum = new int [numberOfColumn];
	for(int j = 0; j < numberOfColumn; j++) {
	    maximum[j] = P[0][j];
	}

	for (int j = 0; j < numberOfColumn; j++) {
	    for (int i = 0; i < 4; i++) {
	        if (P[i][j] > maximum[j]) maximum[j] = P[i][j];
	    }
	    for (int i = 0; i < 4; i++) {
	        if (P[i][j] == maximum[j]) {
	            C[j] = pos[i];
	            break;
	        }
	    }
	}

	for (int j = 0; j < numberOfColumn; j++) {
	    cout << P[0][j];
	    if (j != numberOfColumn - 1) cout << " ";
	}
	cout << endl;
	for (int j = 0; j < numberOfColumn; j++) {
	    cout << P[1][j];
	    if (j != numberOfColumn - 1) cout << " ";
	}
	cout << endl;
	for (int j = 0; j < numberOfColumn; j++) {
	    cout << P[2][j];
	    if (j != numberOfColumn - 1) cout << " ";
	}
	cout << endl;
	for (int j = 0; j < numberOfColumn; j++) {
	    cout << P[3][j];
	    if (j != numberOfColumn - 1) cout << " ";
	}
	cout << endl;
	for (int j = 0; j < numberOfColumn; j++) {
	    cout << C[j];
	    if (j != numberOfColumn - 1) cout << " ";
	}
}




