#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>

using namespace std;
#define PI 3.1415

int main() {
	int option;
	double A, B, C;
	cin >> option;
	cin >> A;
	cin >> B;
	cin >> C;

	double result;
	switch ( option) {
	    case 1: result = A + B + C; break;
	    case 2: result = 2*(A + B); break;
	    case 3: result = 4*A; break;
	    case 4: result = 2*PI*A; break;
	    case 5: result = sqrt((A + B + C)*(A + B - C)*(B + C - A)*(C + A - B))/4; break;
	    case 6: result = A*B; break;
	    case 7: result = A*A; break;
	    case 8: result = PI*A*A; break;
	}
	cout << result;
}
