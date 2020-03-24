#include <iostream>
using namespace std;

bool check(char* str, char* substr, int start) {
    static int count = 0;
    if (substr[count] == '\0') {
        count = 0;
        return 1;
    }
    else {
        if (str[count + start] == '\0') {
            count = 0;
            return 0;
        }
        else {
            if (substr[count] == str[start + count]) {
                count += 1;
                return check(str, substr, start);
            }
            else {
                count = 0;
                return 0;
            }
        }
    }
}

bool contains(char *str, char *substr) {
    static int start = 0;
    if (check(str, substr, start)) return 1;
    else {
        if (str[start] != '\0') {
            start += 1;
            return (contains(str, substr));
        }
        else return 0;
    }
}


int main() {
    //Viet ham kiem tra xen 1 chuoi co phai la chuoi con cua 1 chuoi khac
    char substr[] = "";
    char str[] = "";
	bool x = contains(str, substr);
	    cout << x << endl;

}

