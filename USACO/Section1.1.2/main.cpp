/*
ID: binhtra1
LANG: C++14
TASK: ride
*/

#include <bits/stdc++.h>

#define TASK "ride"

using namespace std;

void solve_test() {
    ofstream fout (TASK ".out");
    ifstream fin (TASK ".in");
    int a, b; fin >> a >> b;
    fout << a + b << endl;
}

void solve_ride() {
    ofstream fout (TASK ".out");
    ifstream fin (TASK ".in");
    string s1, s2;
    fin >> s1 >> s2;
    long long a = 1, b = 1;
    for (int i = 0; i < (int)s1.size(); i++) {
        a = (a * (s1[i] - 'A' + 1)) % 47;
    }
    for (int i = 0; i < (int)s2.size(); i++) {
        b = (b * (s2[i] - 'A' + 1)) % 47;
    }
    if (a == b) fout << "GO" << endl;
    else fout << "STAY" << endl;
}

int main()
{
   ///solve_test();
   solve_ride();
}
