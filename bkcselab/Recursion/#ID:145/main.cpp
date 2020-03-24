#include <iostream>

using namespace std;

int findLength(char* text, int start) {
    if (text[start] != '\0') {
        return findLength(text, start + 1);
    }
    else return start;
}

void reverse(char* text) {
    // TODO
    int n = findLength(text, 0);
    static int x = n;
    if (x != n/2) {
        swap(text[x - 1], text[n - x]);
        x -= 1;
        return reverse(text);
    }
}

int main()
{
    char a[] = "abcdef";
    reverse(a);
    cout << a;
}
