#include <iostream>
using namespace std;

void revert(char* text, int fromPosition, int toPosition) {
    if (fromPosition >= toPosition) return;
    else {
        swap(text[fromPosition], text[toPosition]);
        return revert(text, fromPosition + 1, toPosition - 1);
    }
}

int main() {
    //Viet ham dao nguoc cac ki tu trong chuoi tu vi tri begin den end
	char a[] = "01234567";
	revert(a, 3, 6);
	for (int i = 0; i < 8; i++) {
	    cout << a[i];
	}
}
