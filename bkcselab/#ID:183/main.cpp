#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>

using namespace std;

void process(const char* fileName) {
    fstream fs(fileName, ios::in);
    if (fs.is_open()) {
        int nWords = 0;
        while (!fs.eof()) {
            string line;
            getline(fs, line);
            stringstream ss(line);
            string word;
            while(ss >> word) nWords += 1;
        }
        cout << nWords;
        fs.close();
    }
}

int main()
{
    process("newfile.txt");
}
