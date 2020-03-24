#include <iostream>
#include <string>
using namespace std;


int main() {
    int number, n0, n1, n2, n3;
    cin >> number;
    n0 = number%10;
    n1 = (number/10)%10;
    n2 = (number/100)%10;
    n3 = (number/1000)%10;
    if (n3 != 0) cout << "-1";
    else {
        switch (n2) {
            case 1: cout << "mộtt trăm "; break;
            case 2: cout << "hai trăm "; break;
            case 3: cout << "ba trăm "; break;
            case 4: cout << "bốn trăm "; break;
            case 5: cout << "năm trăm "; break;
            case 6: cout << "sáu trăm "; break;
            case 7: cout << "bảy trăm "; break;
            case 8: cout << "tám trăm "; break;
            case 9: cout << "chín trăm "; break;
        }
        switch (n1) {
            case 0: if (n0 != 0) cout << "lẻ "; break;
            case 1: cout << "mười "; break;
            case 2: cout << "hai mươi "; break;
            case 3: cout << "ba mươi "; break;
            case 4: cout << "bốn mươi "; break;
            case 5: cout << "năm mươi "; break;
            case 6: cout << "sáu mươi "; break;
            case 7: cout << "bảy mươi "; break;
            case 8: cout << "tám mươi "; break;
            case 9: cout << "chín mươi "; break;
        }
        switch (n0) {
            case 1: {
                if (n1 == 1 || n1 == 0) cout << "một";
                else cout << "mốt"; break;
            }
            case 2: cout << "hai"; break;
            case 3: cout << "ba"; break;
            case 4: cout << "bốn"; break;
            case 5: {
                if (n1 == 0) cout << "năm";
                else cout << "lăm"; break;
            }
            case 6: cout << "sáu"; break;
            case 7: cout << "bảy"; break;
            case 8: cout << "tám"; break;
            case 9: cout << "chín"; break;
        }
    }
}
