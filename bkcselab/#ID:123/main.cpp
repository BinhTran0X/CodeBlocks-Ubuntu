#include <iostream>
using namespace std;

int main() {
	char str1[] = "abcdefsasasas";
	char str2[] = "dfeabcdefffasasasasasasasasfdcwrvffbvdsdv";

	int index[500];
	for (int i = 0; i < 500; i++) index[i] = 0;

	for (int i = 0; str1[i] != '\0'; i++) {
	    for (int j = 0; str2[j] !='\0'; j++) {
	        if (str1[i] == str2[j]) {
	            int k = 0;
	            int total = 0;
	            while (str1[i + k] == str2[j + k] && str1[i + k] != '\0' && str2[j + k] != '\0') {
	                total += 1;
	                k += 1;
	            }
	            index[i] = max(index[i], total);
	        }
	    }
	}

	int maximum = 0;

	for (int i = 0; str1[i] != '\0'; i++) maximum = max(maximum, index[i]);

	for (int i = 0; str1[i] != '\0'; i++) {
	    if (index[i] == maximum) {
	        for (int j = 0; j < maximum; j++) cout << str1[i + j];
	        break;
	    }
	}
}
