#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

ifstream ifs("conf.json"; ifstream::in);
void LoadConfiguration() {
    while (true) {
        string s;
        getline(ifs,s);
        int Pos = s.find("WelcomeText");
        if (Pos != -1) break;
    }
    for (int i = 1; i <= 9; i++) {
        string s;
        getline(ifs,s);
        int L = 14;
        while (s[L] != '"') cout << s[L++];
        cout << '\n';
    }
    string s;
    getline(ifs,s);
    // TODO: write code to load data from the configuration file
}

