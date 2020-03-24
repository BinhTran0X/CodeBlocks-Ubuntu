#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    int h;
    cin >> h;
    // TODO
    int max = 1;
    for (int i = 1; i <= (h-1)/2; i++) {
	    max *= (h - i);
    }
    for (int i = 1; i <= (h-1)/2; i++) {
	    max /= i;
    }

    int len = 2;
    while (max/10) {
	    len += 1;
	    max /= 10;
    }
    //len = 4;
    for (int i = 0; i <= h - 1; i++) {
        int num = 1;
        for (int j = 0; j <= i - 1; j++) {
            if (j != 0) {
                num = num*(i + 1 - j)/j;
                printf("%-*d", len, num);
            }
            else printf("%-*d", len, num);
        }
        if (i == h - 1) cout << 1;
        else cout << 1 << "\n";
    }
}
