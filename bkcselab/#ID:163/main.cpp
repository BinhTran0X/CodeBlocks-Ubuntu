#include <iostream>

using namespace std;

class Integer {
	int value;
public:
    Integer(double d) {
        this -> value = (int)d;
    }
    void toString(char* &c) {
        int Value = this -> value;
        if (Value == 0) {
            c = new char[2];
            c[0] = char(0 + 48);
            c[1] = '\0';
            return;
        }
        int Count = 0;
        int N = Value;
        while (Value) {
            Count++;
            Value /= 10;
        }
        char *Res = new char[Count];
        c = new char[Count + 1];
        for (int i = 0; i < Count; i++, N /= 10) Res[i] = char(N % 10 + 48);
        for (int i = 0; i < Count; i++) c[i] = Res[Count - i - 1];
        c[Count] = '\0';
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
