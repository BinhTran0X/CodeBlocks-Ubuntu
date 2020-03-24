#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <cctype>

using namespace std;

void process(const char* fileName) {
    char** arr;
    int M, N;
    fstream fs(fileName, ios::in);
    if (fs.is_open()) {
        fs >> M;
        fs >> N;
        arr = new char*[M];
        for (int i = 0; i < M; i++) {
            arr[i] = new char [N];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                fs >> arr[i][j];
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) cout << arr[i][j];
            cout << endl;
        }
        fs.close();
    }
}

int main()
{
    process("newfile.txt");
}
