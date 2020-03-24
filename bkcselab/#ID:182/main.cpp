#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

void readfile(char* fileName) {
    // TODO
    fstream fs(fileName, ios::in);
    if (fs.is_open()) {
        int table[26];
        for (int i = 0; i < 26; i++) {
            table[i] = 0;
        }
        string line;
        int nLines = 0;
        while(!fs.eof()) {
            getline(fs, line);
            nLines += 1;
            char x;
            int len = (int)line.size();
            for (int i = 0; i < len; i++) {
                x = line[i];
                x = toupper(x);
                table[x - 'A'] += 1;
            }
        }
        cout << "Lines = " << nLines;
        for (int i = 0; i < 26; i++) {
            cout << endl << char(i + 'A') << " = " << table[i];
        }
        fs.close();
    }

}

int main()
{
    readfile("newfile.txt");
}
